#ifndef DLINK_H
#define DLINK_H

#include <sstream>
#include <string>

template <class T> class DList;
template <class T> class DListIterator;

template <class T>
class DLink
{
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T value;
	DLink<T> *next;
    DLink<T> *previous;

	friend class DList<T>;
	friend class DListIterator<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), next(0), previous(0) {}

template <class T>
DLink<T>::DLink(T val, DLink* nxt, DLink* prev) 
    : value(val), next(nxt), previous(prev) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) 
    : value(source.value), next(source.next), previous(source.previous) {}

template <class T>
class DList {
    public:
        DList();
        DList(const DList<T>&);
        ~DList();

        void clear();
        std::string toStringForward() const;
        std::string toStringBackward() const;
        void insertion(T);
        int search(T);
        void update(int, T);
        T deleteAt(int);
    private:
        DLink<T> *head;
        DLink<T> *tail;
        int size;

        friend class DListIterator<T>;
        void iterate(bool, DLink<T>*&);
        DLink<T>* dlinkAt(int index);
        bool empty();
};

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
T DList<T>::deleteAt(int index) {
    DLink<T>* toDelete;
    toDelete = dlinkAt(index);
    toDelete->next->previous = toDelete->previous;
    toDelete->previous->next = toDelete->next;
    T value = toDelete->value;
    delete toDelete;
    size--;
    return value;
}

template <class T>
void DList<T>::iterate(bool forward, DLink<T>*& dlink) {
    if (dlink == 0) {
        return;
    }
    if (forward) {
        dlink = dlink->next;
    } else {
        dlink = dlink->previous;
    }
}

template <class T>
DLink<T>* DList<T>::dlinkAt(int index) {
    if (empty()) {
        return head;
    }
    DLink<T> *link;
    link = head;
    bool fromHead = true;
    int indexFrom = 0;
    if (index >= size / 2) {
        link = tail;
        fromHead = false;
        indexFrom = size - 1;
    }
    while (indexFrom != index) {
        iterate(fromHead, link);
        indexFrom += fromHead ? 1 : -1;
    }
    return link;
}


template <class T>
void DList<T>::update(int index, T value) {
    if (empty()) {
        return;
    }
    DLink<T>* toUpdate;
    toUpdate = dlinkAt(index);
    toUpdate->value = value;
}

template <class T>
int DList<T>::search(T value) {
    DLink<T>* dlink;
    dlink = head;
    int index = 1;
    while (dlink->value != value) {
        dlink = dlink->next;
        if (dlink == 0) {
            return -1;
        }
        index++;
    }
    return index - 1;
}

template <class T>
void DList<T>::insertion(T value) {
    DLink<T> *newTail;
    newTail = new DLink<T>(value);
    size++;
    if (empty()) {
        head = newTail;
        tail = newTail;
        return;
    }
    tail->next = newTail;
    newTail->previous = tail;
    tail = newTail;
}

template <class T>
bool DList<T>::empty() {
    return (head == 0);
}

template <class T>
void DList<T>::clear() {
    DLink<T> *toDelete, *stored;
    toDelete = head;
    while (toDelete->next != 0) {
        stored = toDelete->next;
        delete toDelete;
        toDelete = stored;
    }
    head = 0;
    tail = 0;
    size = 0;
}

template <class T>
std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;
                                                 
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
                                                 
template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;
                                                 
	p = tail;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->previous != 0) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

#endif
