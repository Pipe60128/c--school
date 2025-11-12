#pragma once
#include "AVLTree.h"
#include <iostream>
using namespace std;
template <typename T>
void AVLTree<T>::print(Node<T>* node, int nr, int nl) const {
    if (node == nullptr) return ;
    print(node->getRight(), nr + 1, nl);
    for (int i = 0; i < nr + nl; i++){
        cout<<"  ";
        i-1; 
        for (int j = 0; j < nr + nl; j++){
        cout<<" "; 
        j-1;
        }
    }
    if (nr < nl + 1){
        cout<<node->getData()<<"-<"<<endl;
    } else if ( nr - 1 > nl ){
        cout<<node->getData()<<"-<"<<endl;
    } else {
        cout<<node->getData()<<endl;
    }
    print(node->getLeft(), nr, nl + 1);
}
/* util */
template <typename T>
int AVLTree<T>::height(Node<T>* n) const {
    return n ? n->getHeight():0;
}
template <typename T>
int AVLTree<T>::balanceFactor(Node<T>* n) const {
    if (!n) {
        return 0;
    }
    return height(n->getLeft()) - height(n->getRight());
}
template <typename T>
int AVLTree<T>::maxValue(int a, int b) const {
    return (a>b) ? a : b;
}

/* rotations */
template <typename T>
Node<T>* AVLTree<T>::rotateRight(Node<T>* node) {
    Node<T>* temp= node->getLeft();
    Node<T>* temp2= temp->getRight();
    temp->setRight(node);
    node->setLeft(temp2);
    node->setHeight(1+ maxValue(height(node->getLeft()), height(node->getRight())));
    temp->setHeight(1+ maxValue(height(temp->getRight()), height(temp->getLeft())));
    return temp;
}
template <typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T>* node) {
    Node<T>* temp= node->getRight();
    Node<T>* temp2= temp->getLeft();
    temp->setLeft(node);
    node->setRight(temp2);
    node->setHeight(1+ maxValue(height(node->getLeft()), height(node->getRight())));
    temp->setHeight(1+ maxValue(height(temp->getRight()), height(temp->getLeft())));
    return temp;
}
template <typename T>
Node<T>* AVLTree<T>::rotateLeftRight(Node<T>* node) {
    node->setLeft( rotateLeft(node->getLeft()));
    return rotateRight(node);
}

template <typename T>
Node<T>* AVLTree<T>::rotateRightLeft(Node<T>* node) {
    node->setRight( rotateRight(node->getRight()));
    return rotateLeft(node);
}
template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, const T& value) {
    if (!node) {
        return new Node<T>(value);
    }
    if (value < node->getData()) {
        node->setLeft(insert(node->getLeft(),value));
    }else if (value > node->getData()) {
        node->setRight(insert(node->getRight(), value));
    }else {
        return node;
    }

    node->setHeight(1 + maxValue(height(node->getLeft()),height(node->getRight())));
    const int bf= balanceFactor(node);
    if (bf > 1 && value < node->getLeft()->getData()) {
        return rotateRight(node);
    }
    if (bf< -1 && value > node->getRight()->getData()) {
        return rotateLeft(node);
    }
    if (bf > 1 && value > node->getLeft()->getData()) {
        return rotateLeftRight(node);
    }
    if (bf< -1 && value < node->getRight()->getData()) {
        return rotateRightLeft(node);
    }
    return node;
}
template <typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, const T& value) {
     if (node == nullptr) return node; 

    if (value < node->getData()) {
        node->setLeft(remove(node->getLeft(), value));
    } else if (value > node->getData()) {
        node->setRight(remove(node->getRight(), value));
    } else {
        if (node->getLeft()==nullptr && node->getRight()==nullptr) {
            delete node;
            return nullptr;
        } else if (node->getRight() == nullptr) {
            Node<T>* temp = node->getLeft();
            delete node;
            return temp;

        } else if (node->getLeft() == nullptr) {
            Node<T>* temp = node->getRight();
            delete node;
            return temp;
        } else {
            Node<T>* temp = node->getLeft();
            while(temp && temp->getRight() != nullptr) {
                temp = temp->getRight();
            }
            T newData = temp->getData();
            node->setData(newData);
            node->setLeft(remove(node->getLeft(), node->getData()));
        }
    } 
    node->setHeight(1 + maxValue(height(node->getLeft()),height(node->getRight())));
    const int bf= balanceFactor(node);
    if (bf > 1 && value < node->getLeft()->getData()) {
        return rotateRight(node);
    }
    if (bf< -1 && value > node->getRight()->getData()) {
        return rotateLeft(node);
    }
    if (bf > 1 && value > node->getLeft()->getData()) {
        return rotateLeftRight(node);
    }
    if (bf< -1 && value < node->getRight()->getData()) {
        return rotateRightLeft(node);
    }
    return node;
}
template <typename T>
void AVLTree<T>::destroy(Node<T>* node) {
    delete node;
    node = nullptr;
}

template<typename T>
bool AVLTree<T>::search(Node<T>* node, const T& value) const {
    if (node == nullptr) {
        return false;
    }
    if (value > node->getData()){
        cout<<node->getData()<<"-> ";
    } else if(value == node->getData()) {
        cout<<node->getData();
    } else if (!node) {
        cout<<"->";
        return false;
    }
    
    if (value==node->getData()) {
        return true;
    }
    if (value < node->getData()) {
        return search(node->getLeft(), value);
    }
    return search(node->getRight(), value);
}

template<typename T>
void AVLTree<T>::search(const T& v) const {
    cout<<"_________________________"<<"\n|       BUSCANDO        |"<<"\n|___________________s____|"<<endl;
    bool result = search(root, v);
    if (result != true){
        cout<<" NO SE HA ENCONTRADO EL ELEMENTO"<<endl;
    }
    
}


template <typename T>
AVLTree<T>::~AVLTree() {
    
}
template <typename T>
void AVLTree<T>::clear() {
    destroy(root);

}
template <typename T>
void AVLTree<T>::remove(const T& value) {
    remove(root, value);

}
template <typename T>
void AVLTree<T>::print() const {
    print(root,0,0);
}
template <typename T>
void AVLTree<T>::insert(const T& value) {
    root= insert(root, value);
}

