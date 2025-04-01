#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>

using namespace std;

template <typename K, typename V>
class BinarySearchTree {
private:
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
        Node(K k, V v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, K key, V value) {
        if (!node) {
            node = new Node(key, value);
            return;
        }
        if (key < node->key) {
            insert(node->left, key, value);
        } else if (key > node->key) {
            insert(node->right, key, value);
        } else {
            node->value = value;
        }
    }

    V* search(Node* node, K key) {
        if (!node) return nullptr;
        if (key == node->key) return &node->value;
        return (key < node->key) ? search(node->left, key) : search(node->right, key);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(K key, V value) {
        insert(root, key, value);
    }

    V* search(K key) {
        return search(root, key);
    }
};

#endif
