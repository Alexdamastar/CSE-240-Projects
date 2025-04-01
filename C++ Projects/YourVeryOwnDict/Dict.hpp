#ifndef DICT_HPP
#define DICT_HPP

#include <vector>
#include "BinarySearchTree.hpp"

using namespace std;

template <typename K, typename V>
class Dict
{
    public:
        Dict () {}
        void add (K key, V value);
        V& operator[] (K key);
    private:
        BinarySearchTree<K,V> bt;
};

template <typename K, typename V>
void Dict<K, V>::add(K key, V value)
{
    bt.insert(key, value);
}

template <typename K, typename V>
V& Dict<K, V>::operator[](K key)
{
    try {
        return bt.search(key); // Search for the key
    } catch (runtime_error&) {
        bt.insert(key, V());
        return bt.search(key);
    }
}

#endif