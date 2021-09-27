#ifndef LIST_H
#define LIST_H

#include <sstream>
#include <string>

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template<class T>
class List
{
    private:
        Link<T>* head;
        int	size;

        friend class ListIterator<T>;
        Link<T>* linkAt(int);
    public:
        List();
        ~List();
        std::string toString() const;
        void clear();
        void insertion(T);
        bool empty() const;
        int search(T);
        void update(int, T);
        T deleteAt(int);
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
    clear();
}

template <class T>
T List<T>::deleteAt(int index) {
    Link<T> *toDelete, *prevToDelete;
    toDelete = linkAt(index);
    T value = toDelete->value;
    size--;
    if (index == 0) {
        head = toDelete->next;
    } else {
        prevToDelete = linkAt(index - 1);
        prevToDelete->next = toDelete->next;
    }
    delete toDelete;
    return value;
}

template <class T>
void List<T>::update(int index, T val) {
    Link<T> *toUpdate;
    // cannot update an item in an empty list
    if (empty()) {
        return;
    }
    toUpdate = linkAt(index);
    // toUpdate = head;
    // int i = 0;
    // for (; i < index; i++) {
    //     toUpdate = toUpdate->next;
    // }
    toUpdate->value = val;
}

template <class T>
Link<T>* List<T>::linkAt(int index) {
    Link<T> *link;
    link = head;
    int i = 0;
    for (; i < index; i++) {
        link = link->next;
    }
    return link;
}

template <class T>
int List<T>::search(T val) {
    Link<T> *link;
    if (empty()) {
        return -1;
    }
    link = head;
    int index = 1;
    while (link->value != val) {
        link = link->next;
        if (link == 0) {
            return -1;
        }
        index++;
    }
    return index - 1;
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::insertion(T val) {
    Link<T> *newLink, *next;
    newLink = new Link<T>(val);
    if (empty()) {
        newLink->next = head;
        head = newLink;
        return;
    }
    next = head;
    while (next->next != 0) {
        next = next->next;
    }
    newLink->next = 0;
    next->next = newLink;
    size++;
}

template <class T>
void List<T>::clear() {
    Link<T> *link, *nextLink;
    link = head;
    while (link != 0) {
        nextLink = link->next;
        delete link;
        link = nextLink;
    }
    head = 0;
    size = 0;
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

#endif
