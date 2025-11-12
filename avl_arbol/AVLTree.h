#ifndef AVL_TREE_H
#define AVL_TREE_H
#include <iostream>
#include "Node.h"

template <typename T>
class AVLTree {
private:
    Node<T>* root;
    void print(Node<T>* node, int nr, int nl) const;
    /* util */
    int height(Node<T>* n) const;
    int balanceFactor(Node<T>* n) const;
    int maxValue(int a, int b) const;

    /* rotations */
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
    Node<T>* rotateLeftRight(Node<T>* node);
    Node<T>* rotateRightLeft(Node<T>* node);
    Node<T>* insert(Node<T>* node, const T& value);
    Node<T>* remove(Node<T>* node, const T& value);
    void destroy(Node<T>* node);
    bool search(Node<T>* node, const T& value) const;


public:
    AVLTree(): root(nullptr){}
    ~AVLTree();
    void clear();
    void print() const;
    void insert(const T& value);
    void remove(const T& value);
    void search(const T& value) const;
    


};
#include "AVLTree.tpp"
#endif
