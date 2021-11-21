#ifndef BST_H
#define BST_H

#include <iostream>
#include <queue>
#include <string>
#include <sstream>

typedef std::string str;
typedef std::stringstream strs;
typedef unsigned int u32;

// >>> class declarations
template <typename T>
class Node;

template <typename T>
class BST;
// <<< class declarations

enum Traversal {
    PREORDER,
    INORDER,
    POSTORDER,
    LEVEL_BY_LEVEL,
};

// >>> Node class definition
template <typename T>
class Node {
    private:
        T value;

        Node* left;
        Node* right;

        Node(T);
        Node(T, Node*, Node*);
        ~Node();

        friend class BST<T>;
};

template <typename T>
Node<T>::Node(T value_) {
    value = value_;
    left = 0;
    right = 0;
}

template <typename T>
Node<T>::Node(T value_, Node* left_, Node* right_) {
    value = value_;
    left = left_;
    right = right_;
}

template <typename T>
Node<T>::~Node() {
    delete left;
    delete right;
}
// <<< Node class definition

// >> BST class definition
template <typename T>
class BST {
    private:
        Node<T>* root;
        u32 tree_height;

        void traversal(strs&, Traversal);
        void preorder(strs&, Node<T>*&);
        void inorder(strs&, Node<T>*&);
        void postorder(strs&, Node<T>*&);
        void level_by_level(strs&, Node<T>*&);
        void retrieve_children(std::queue<Node<T>*>&, Node<T>*&);
    public:
        BST();
        ~BST();

        void add(T);

        str ancestors(const T&);
        str visit();

        u32 height();
        u32 whatlevelamI(const T&);
};

template <typename T>
BST<T>::BST() {
    root = 0;
    tree_height = 0;
}

template <typename T>
BST<T>::~BST() {
    // TODO
    delete root;
    root = 0;
}

template <typename T>
void BST<T>::add(T value) {
    if (root == 0) {
        root = new Node<T>(value);
        tree_height = 1;
        return;
    }

    Node<T>* node;
    Node<T>* parent;

    node = root;
    parent = root;

    u32 node_height = 0;

    while (node != 0) {
        parent = node;

        if (value >= node->value) {
            node = node->right;
        } else if (value < node->value) {
            node = node->left;
        }

        node_height++;
    }

    if (value >= parent->value) {
        parent->right = new Node<T>(value);
    } else if (value < parent->value) {
        parent->left = new Node<T>(value);
    }

    if (++node_height > tree_height) {
        tree_height = node_height;
    }
}

template <typename T>
str BST<T>::ancestors(const T& value) {
    strs ancestors_str("");

    Node<T>* node = root;

    ancestors_str << "[";

    while (node != 0 && node->value != value) {
        ancestors_str << node->value;

        if (value >= node->value) {
            node = node->right;
        } else if (value < node->value) {
            node = node->left;
        }

        if (node != 0 && node->value != value) {
            ancestors_str << " ";
        }
    }

    if (node == 0) {
        return "[]";
    }

    ancestors_str << "]";

    return ancestors_str.str();
}

template <typename T>
void BST<T>::traversal(strs& visited, Traversal trav) {
    Node<T>* node = root;

    visited << "[";

    if (node != 0) {
        switch (trav) {
            case PREORDER:
                preorder(visited, node);
                break;
            case INORDER:
                inorder(visited, node);
                break;
            case POSTORDER:
                postorder(visited, node);
                break;
            case LEVEL_BY_LEVEL:
                level_by_level(visited, node);
                break;
        }
    }

    visited << "]";
}

template <typename T>
void BST<T>::preorder(strs& visited, Node<T>*& node) {
    visited << node->value;

    if (node->left != 0) {
        visited << " ";
        preorder(visited, node->left);
    }

    if (node->right != 0) {
        visited << " ";
        preorder(visited, node->right);
    }
}

template <typename T>
void BST<T>::inorder(strs& visited, Node<T>*& node) {
    if (node->left != 0) {
        inorder(visited, node->left);
        visited << " ";
    }

    visited << node->value;

    if (node->right != 0) {
        visited << " ";
        inorder(visited, node->right);
    }
}

template <typename T>
void BST<T>::postorder(strs& visited, Node<T>*& node) {
    if (node->left != 0) {
        postorder(visited, node->left);
        visited << " ";
    }

    if (node->right != 0) {
        postorder(visited, node->right);
        visited << " ";
    }

    visited << node->value;
}

template <typename T>
void BST<T>::level_by_level(strs& visited, Node<T>*& node) {
    visited << node->value;

    std::queue<Node<T>*> children;

    if (node->left != 0) {
        children.push(node->left);
    }

    if (node->right != 0) {
        children.push(node->right);
    }

    while (!children.empty()) {
        Node<T>* child = children.front(); 
        children.pop();

        visited << " " << child->value;

        retrieve_children(children, child);
    }
}

template <typename T>
void BST<T>::retrieve_children(std::queue<Node<T>*>& children, 
                               Node<T>*& child) {
    if (child->left != 0) {
        children.push(child->left);
    }

    if (child->right != 0) {
        children.push(child->right);
    }
}

template <typename T>
str BST<T>::visit() {
    strs visited("");

    traversal(visited, PREORDER);
    visited << "\n";

    traversal(visited, INORDER);
    visited << "\n";

    traversal(visited, POSTORDER);
    visited << "\n";

    traversal(visited, LEVEL_BY_LEVEL);

    return visited.str();
}

template <typename T>
u32 BST<T>::height() {
    return tree_height;
}

template <typename T>
u32 BST<T>::whatlevelamI(const T& value) {
    u32 level = 0;

    Node<T>* node = root;

    while (node != 0) {
        if (value >= node->value) {
            node = node->right;
        } else if (value < node->value) {
            node = node->left;
        }

        level++;
    }

    return level;
}
//         10
//        /  \
//       8    12
//              \
//               110
//              /   \
//            18     112
//
//
// <<< BST class definition

#endif
