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
    V* result = bt.search(key); // Assuming search() returns a pointer or nullptr
    if (!result) {
        bt.insert(key, V{});  // Insert a default-constructed value
        result = bt.search(key); // Search again to get a valid reference
    }
    return *result;
}

#endif