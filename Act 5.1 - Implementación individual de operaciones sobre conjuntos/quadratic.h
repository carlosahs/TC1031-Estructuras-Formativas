#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <iostream>
#include <sstream>
#include <string>

typedef unsigned int u32;
typedef std::string str;
typedef std::stringstream strs;

template <typename K, typename V>
class Quadratic {
    private:
        u32 size;
        u32 inserted;

        K empty_key;

        u32 (*hash_function) (const K);

        K* keys;
        V** values;

        u32 quadratic_probing(K, K);
    public:
        Quadratic(u32, K, u32 (*) (const K));
        ~Quadratic();

        str toString();

        void put(K, V);

        V get(K);
};

template <typename K, typename V>
Quadratic<K, V>::Quadratic(u32 size_, K empty_key_, 
                           u32 (*hash_function_) (const K)) {
    size = size_;
    empty_key = empty_key_;
    hash_function = hash_function_;

    inserted = 0;

    keys = new K[size];
    values = new V*[size];

    for (u32 i = 0; i < size; i++) {
        keys[i] = empty_key;
        values[i] = 0; // set initial values to null
    }
}

template <typename K, typename V>
Quadratic<K, V>::~Quadratic() {
    delete [] keys;

    for (u32 i = 0; i < size; i++) {
        delete values[i];
    }

    delete [] values;
}

template <typename K, typename V>
str Quadratic<K, V>::toString() {
    strs hash_str("");

    for (u32 i = 0; i < size; i++) {
        if (keys[i] == empty_key) {
            continue;
        }

        hash_str << "(";
        hash_str << i << " ";
        hash_str << keys[i] << " : ";
        hash_str << *values[i] << ") ";
    }

    return hash_str.str();
}

template <typename K, typename V>
u32 Quadratic<K, V>::quadratic_probing(K key, K cmp_key) {
    u32 idx = hash_function(key) % size;
    u32 trial = 1;

    while (keys[idx] != cmp_key) {
        idx = (idx + trial * trial) % size;
        trial++;
    }

    return idx;
}

template <typename K, typename V>
void Quadratic<K, V>::put(K key, V value) {
    if (inserted == size) {
        return;
    }

    u32 idx = quadratic_probing(key, empty_key);

    keys[idx] = key;
    values[idx] = new V;
    *values[idx] = value;

    inserted++;
}

template <typename K, typename V>
V Quadratic<K, V>::get(K key) {
    u32 idx = quadratic_probing(key, key);

    return *values[idx];
}

#endif
