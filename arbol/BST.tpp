#pragma once
#include "BST.h"
#include <iostream>
using namespace std;

template<typename T>
BST<T> :: BST(): root(nullptr) {}

template<typename T>
BST<T> :: ~BST() {
    cout<<"\n*********************************"<<endl;
    cout<<"*******ACTIVANDO DESTRUCTOR******"<<endl;
    cout<<"*********************************"<<endl;
    clear();
}

template<typename T>
int BST<T> :: height() {
    int num = height(root);
    return num;
}

template<typename T>
int BST<T> :: height(Node<T>* root) {
    if (root == nullptr) return 0;
    Node<T>* temp = root;
    int hl = height(temp->getLeft());
    int hr =  height(temp->getRight());
    int value;
    if (hl < hr){
        value = hr;
    } else {
        value = hl;
    }
    return 1 + (value);

}

template<typename T>
int BST<T> :: whatLevelAmI(const T& v){
    int count = 0;
    Node<T>* temp = root;
    while (temp != nullptr) {
        if (v < temp->getData()){
            temp = temp->getLeft();
        } else if (v > temp->getData()){
            temp = temp->getRight();
        } else if ( v == temp->getData()){
            return count;
        }
        count++;
    }
    return -1;
}

template<typename T>
bool BST<T> :: isEmpty() {
    return root == nullptr;
}

template<typename T>
void BST<T> :: print(Node<T>* root, int nr, int nl){
    Node<T>* current = root;
    if (current == nullptr) return ;
    print(current->getRight(), nr + 1, nl);
    for (int i = 0; i < whatLevelAmI(current->getData()); i++){
        cout<<"  ";
        for (int j = 0; j < whatLevelAmI(current->getData()); j++){
        cout<<" "; 
        }
    }
    if (nr < height(current) + (nr - 1) ){
        cout<<current->getData()<<"-<"<<endl;
    } else if ( nl > height(current) + (nl-1) ){
        cout<<current->getData()<<"-<"<<endl;
    } else {
        cout<<current->getData()<<endl;
    }
    print(current->getLeft(), nr, nl + 1);

}

template<typename T>
void BST<T> :: print() {
    cout<<"\n         MOSTRANDO ARBOL\n"<<endl;
    print(root,0,0);
}

template<typename T>
void BST<T> :: clear(Node<T>* root) {
    if (root == nullptr) return;
    clear(root->getLeft());
    clear(root->getRight());
    delete root;
}

template<typename T>
void BST<T> :: clear() {
    cout<<"\n limpiando arbol..."<<endl;
    clear(root);
    root = nullptr;
}

template<typename T>
void BST<T> :: insert(const T& v) {
    Node<T>* newNode = new Node<T>(v);
    if ( root == nullptr) {
        root = newNode;
        return;
    }
    Node<T>* temp = root;
    Node<T>* parent = nullptr;
    while (temp != nullptr) {
        parent = temp;
        if (v < temp->getData()){
            temp = temp->getLeft();
        } else if (v > temp->getData()){
            temp = temp->getRight();
        } else {
            return;
        }
    }
    if (v < parent->getData()){
        parent->setLeft(newNode);
    } else {
        parent->setRight(newNode);
    }
    delete temp;
}

template<typename T>
bool BST<T>::search(Node<T>* root, const T& v) const {
    if (root== nullptr) {
        return false;
    }
    cout<<"Visitando: "<<root->getData()<<endl;
    if (v==root->getData()) {
        return true;
    }
    if (v < root->getData()) {
        cout<<"Moviendo izquierda...\n"<<endl;
        return search(root->getLeft(), v);
    }
    cout<<"Moviendo derecha...\n"<<endl;
    return search(root->getRight(), v);
}

template<typename T>
bool BST<T>::search(const T& v) const {
    cout<<"_____________________"<<"\n|     BUSCANDO      |"<<"\n|___________________|"<<endl;
    bool result = search(root, v);
    if (result != true){
        cout<<"NO SE HA ENCONTRADO EL ELEMENTO: "<< v <<endl;
        return result;
    } else {
        cout<<" SE HA ENCONTRADO EL ELEMENTO: "<< v <<endl;
        return result;
    }
}

template <typename T>
void  BST<T> :: visit(Node<T>* node) const{
    cout<<"Vsistando: "<<node->getData()<<endl;
}

template <typename T>
void  BST<T> :: inOrder(Node<T>* node) const{
    if (node == nullptr) return;
    inOrder(node->getLeft());
    visit(node);
    inOrder(node->getRight());
}

template <typename T>
void  BST<T> :: inOrder() const{
    inOrder(root);
}

template <typename T>
void  BST<T> :: preOrder(Node<T>* node) const{
    if (node == nullptr) return;
    visit(node);
    postOrder(node->getLeft());
    postOrder(node->getRight());
    
}

template <typename T>
void  BST<T> :: preOrder() const{
    preOrder(root);
}

template <typename T>
void  BST<T> :: postOrder(Node<T>* node) const{
    if (node == nullptr) return;
    postOrder(node->getLeft());
    postOrder(node->getRight());
    visit(node);
    
}

template <typename T>
void  BST<T> :: postOrder() const{
    postOrder(root);
}

template <typename T>
void  BST<T> :: remove(const T& v) {
    root = removeNode(root, v);
}

//no funciona bien 
template <typename T>
Node<T>*  BST<T> :: removeNode(Node<T>* node, const T& v) {
    if (node == nullptr) return node;

    if (v < node->getData()) {
        node->setLeft(removeNode(node->getLeft(), v));
    } else if (v > node->getData()) {
        node->setRight(removeNode(node->getRight(), v));
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
            node->setLeft(removeNode(node->getLeft(), node->getData()));
        }
    } 
    return node;
}

template <typename T>
void  BST<T> :: ancestors(const T& v) {
    cout<<"_________________________________"<<endl; 
    cout << "  Ancestros de " << v <<":"<<endl;
    if (ancestors(root, v) != true) {
        cout << "No se encontró el valor en el árbol."<<endl;
    }
    cout<<"\n_________________________________\n"<<endl;

}

template <typename T>
bool  BST<T> :: ancestors(Node<T>* node , const T& v) {
    if (node == nullptr) return false;
    if(node->getData() ==  v) return true;
    bool fILeft = ancestors(node->getLeft(), v);
    bool fIRight = ancestors(node->getRight(), v);
    if (fILeft != false || fIRight != false) {
        cout<< "-> " << node->getData();
        return true;
    }
    return false;
}