#pragma once
#include "Stack.h"
#include "Node.h"
using namespace std;
#include <iostream>

template <typename T>
void Stack<T>:: clear(){
    Node<T>* current = topNode;
    while (current){
        Node<T>* next = current->next;
        delete current;
        current = next;
        --count;
    }
    topNode = nullptr;
}

template <typename T>
void Stack<T> :: push(const T& v){
    Node<T>* newNode = new Node(v);
    newNode->next = topNode;
    topNode = newNode;
    ++count;
}

template <typename T>
T Stack<T> :: pop(){
    if(isEmpty()) {
        cout << "Empty stack!" << endl;
    } else {
        Node<T>* temp = topNode;
        topNode = topNode->next;
        T returnValue = temp->data;
        delete temp;
        --count;
        return returnValue;
    }
}

template <typename T>
T Stack<T>::top() {
    if(isEmpty()) {
        cout << "Empty stack!" << endl;
    } else {
         return topNode->data;
    }
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void Stack<T>::print() const {
    if (isEmpty()) {
        cout << "Lista Vacia!" << endl;
    } else {
        const Node<T>* current = topNode;
        cout << "[";
        while (current) {
            cout << " " << current->data << " ->";
            current = current->next;
        }
        cout << "]" << endl;
    }
}
