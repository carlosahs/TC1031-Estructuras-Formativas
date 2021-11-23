#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>

typedef std::string str;
typedef std::stringstream strs;
typedef unsigned int u32;

template <typename T>
class Heap {
    private:
        T* elements;

        u32 capacity;
        u32 inserted;

        void heapify_down(u32);
        void heapify_up(u32);
        void swap(u32, u32);
    public:
        Heap(u32);
        ~Heap();

        str toString() const;

        void push(T);
        void pop();

        T top() const;

        u32 size() const;

        bool empty();
        bool full();
};

template <typename T>
void Heap<T>::heapify_down(u32 root_idx) {
    u32 left_idx = root_idx * 2 + 1;
    u32 right_idx = root_idx * 2 + 2;

    if (left_idx >= inserted) {
        return;
    }

    if (elements[root_idx] > elements[left_idx]) {
        swap(root_idx, left_idx);
        heapify_down(left_idx);
    }

    if (elements[root_idx] > elements[right_idx]) {
        swap(root_idx, right_idx);
        heapify_down(right_idx);
    }
}

template <typename T>
void Heap<T>::heapify_up(u32 bottom_idx) {
    if (bottom_idx == 0) {
        return;
    }

    u32 root_idx = (bottom_idx - 1) / 2;

    if (elements[root_idx] > elements[bottom_idx]) {
        swap(root_idx, bottom_idx);
        heapify_up(root_idx);
    }
}

template <typename T>
void Heap<T>::swap(u32 i, u32 j) {
    T tmp = elements[i];

    elements[i] = elements[j];
    elements[j] = tmp;
}

template <typename T>
Heap<T>::Heap(u32 capacity_) {
    capacity = capacity_;
    inserted = 0;

    elements = new T[capacity];
}

template <typename T>
Heap<T>::~Heap() {
    delete [] elements;
}

template <typename T>
str Heap<T>::toString() const {
	strs aux;
	aux << "[";	for (unsigned int i = 0; i < inserted; i++) {
		if (i != 0) {
			aux << " ";
		} aux << elements[i];
	} aux << "]";
	return aux.str();
}

template <typename T>
void Heap<T>::push(T new_element) {
    if (full()) {
        return;
    }

    elements[inserted] = new_element;
    heapify_up(inserted);
    inserted++;
}

template <typename T>
void Heap<T>::pop() {
    if (empty()) {
        return;
    }

    elements[0] = elements[--inserted];
    heapify_down(0);
}

template <typename T>
T Heap<T>::top() const {
    return elements[0];
}

template <typename T>
u32 Heap<T>::size() const {
    return inserted;
}

template <typename T>
bool Heap<T>::empty() {
    return inserted == 0;
}

template <typename T>
bool Heap<T>::full() {
    return inserted == capacity;
}

#endif
