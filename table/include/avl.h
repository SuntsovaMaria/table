#ifndef AVL_H
#define AVL_H

#pragma once
#include <iostream>
#include <string>
#include "list.h"
#include "poly.h"

using namespace std;

template<typename TKey, typename TValue>
class AVLTreeNode {
public:
    TKey key;
    TValue value;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;

    AVLTreeNode(const TKey& key, const TValue& value)
        : key(key), value(value), left(nullptr), right(nullptr), height(1) {}
};

template<typename TKey, typename TValue>
class AVLTree {
private:
    AVLTreeNode<TKey, TValue>* root;

    int height(AVLTreeNode<TKey, TValue>* node);
    int balanceFactor(AVLTreeNode<TKey, TValue>* node);
    AVLTreeNode<TKey, TValue>* rightRotate(AVLTreeNode<TKey, TValue>* y);
    AVLTreeNode<TKey, TValue>* leftRotate(AVLTreeNode<TKey, TValue>* x);
    AVLTreeNode<TKey, TValue>* minValueNode(AVLTreeNode<TKey, TValue>* node);
    AVLTreeNode<TKey, TValue>* insert(AVLTreeNode<TKey, TValue>* node, const TKey& key, const TValue& value);
    AVLTreeNode<TKey, TValue>* remove(AVLTreeNode<TKey, TValue>* node, const TKey& key);
    AVLTreeNode<TKey, TValue>* search(AVLTreeNode<TKey, TValue>* node, const TKey& key);
    void print(AVLTreeNode<TKey, TValue>* node);
    void deleteTree(AVLTreeNode<TKey, TValue>* node);

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree();
    void insert(const TKey& key, const TValue& value);
    void remove(const TKey& key);
    TValue* search(const TKey& key);
    void print() const;
};

template<typename TKey, typename TValue>
int AVLTree<TKey, TValue>::height(AVLTreeNode<TKey, TValue>* node) {
    if (node == nullptr) {
        return 0;
    }
    else {
        return node->height;
    }
}

template<typename TKey, typename TValue>
int AVLTree<TKey, TValue>::balanceFactor(AVLTreeNode<TKey, TValue>* node) {
    if (node == nullptr) {
        return 0;
    }
    else {
        return height(node->left) - height(node->right);
    }
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::rightRotate(AVLTreeNode<TKey, TValue>* y) {
    AVLTreeNode<TKey, TValue>* x = y->left;
    AVLTreeNode<TKey, TValue>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::leftRotate(AVLTreeNode<TKey, TValue>* x) {
    AVLTreeNode<TKey, TValue>* y = x->right;
    AVLTreeNode<TKey, TValue>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::minValueNode(AVLTreeNode<TKey, TValue>* node) {
    AVLTreeNode<TKey, TValue>* current = node;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current;
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::insert(AVLTreeNode<TKey, TValue>* node, const TKey& key, const TValue& value) {
    if (node == nullptr) {
        return new AVLTreeNode<TKey, TValue>(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, value);
    }
    else {
        node->value = value;
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::remove(AVLTreeNode<TKey, TValue>* node, const TKey& key) {
    if (node == nullptr) return node;

    if (key < node->key) {
        node->left = remove(node->left, key);
    }
    else if (key > node->key) {
        node->right = remove(node->right, key);
    }
    else {
        if (node->left == nullptr || node->right == nullptr) {
            AVLTreeNode<TKey, TValue>* temp;
            if (node->left != nullptr) {
                temp = node->left;
            }
            else {
                temp = node->right;
            }
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else {
                *node = *temp;
            }
            delete temp;
        }
        else {
            AVLTreeNode<TKey, TValue>* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = remove(node->right, temp->key);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if (balance > 1 && balanceFactor(node->left) >= 0) {
        return rightRotate(node);
    }
    if (balance > 1 && balanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template<typename TKey, typename TValue>
AVLTreeNode<TKey, TValue>* AVLTree<TKey, TValue>::search(AVLTreeNode<TKey, TValue>* node, const TKey& key) {
    while (node != nullptr && key != node->key) {
        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return node;
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::print(AVLTreeNode<TKey, TValue>* node) {
    if (node != nullptr) {
        print(node->left);
        cout << node->key << ": ";
        node->value.print();
        cout << endl;
        print(node->right);
    }
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::insert(const TKey& key, const TValue& value) {
    root = insert(root, key, value);
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::remove(const TKey& key) {
    root = remove(root, key);
}

template<typename TKey, typename TValue>
TValue* AVLTree<TKey, TValue>::search(const TKey& key) {
    AVLTreeNode<TKey, TValue>* node = search(root, key);
    if (node != nullptr) {
        return &(node->value);
    }
    else {
        return nullptr;
    }
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::print() const {
    print(root);
}

template<typename TKey, typename TValue>
AVLTree<TKey, TValue>::~AVLTree() {
    deleteTree(root);
}

template<typename TKey, typename TValue>
void AVLTree<TKey, TValue>::deleteTree(AVLTreeNode<TKey, TValue>* node) {
    if (node == nullptr)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}
#endif

