#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
#include <iostream>
using namespace std;
#include "linkedList.h"

//constructor
template <typename T>
LinkedList<T> :: LinkedList(): head(nullptr), n(0){}

//destructor
template <typename T>
LinkedList<T> :: ~LinkedList(){
    clear();
    cout<<"toDO"<<endl;
}

//check if list is empty
template <typename T>
bool LinkedList<T> :: empty() const {
    return n==0 || !head;
}

//print method
template <typename T>
void LinkedList<T> :: print() {
    if (empty()) {
        cout<< "lista vacia" << endl;
    } else {
        const Node<T>* current = head;
        cout<<"[";
        while (current) {
            cout<<" "<<current->data<<" ->";
            current = current->next;
        }
        cout<<"]"<<endl;
    }
}

//pushFront
template <typename T>
void LinkedList<T> :: pushBack(const T& value ){
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        Node<T>* current = head;
        while (current->next) {
            current = current-> next;
        }
        current->next = newNode;
    }
    ++n;
        
    
}

//pushBack method
template <typename T>
void LinkedList<T> :: pushFront(const T& value ){
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    ++n;

}
 //inset method
template <typename T>
bool LinkedList<T> :: insert(unsigned int index, const T& value){
    if (index > n) return false;
    if (index == 0) {
        pushBack(value);
        return true;
    }
    Node<T>* current = head;
    for (int i =0; i < index-1; i++){
        current = current -> next;
    }
    Node<T>* newNode = new Node<T>(value);
    newNode->next = current->next;
    current->next = newNode;
    ++n;
    return true;

}
//remove method 
template <typename T>
bool LinkedList<T>::remove(const T& value) {
    if (empty()) return false;
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current) {
        if (current->data == value) {
            if (previous!= nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            --n;
            return true && cout<<"fisrt element with value "<< value<<" removed"<<endl;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

//clear method
template <typename T>
void LinkedList<T> :: clear(){
    Node<T>* current = head;
    while (current){
        Node<T>* next = current->next;
        delete current;
        current = next;
        --n;
    }
    head = nullptr;
}

//size method
template <typename T> 
unsigned int LinkedList<T> :: size() const{
    unsigned int nSize = 0;
    Node<T>* current = head;
    while (current) {
        ++nSize;
        current = current -> next;
    }
    return nSize;

}

template <typename T>
T* LinkedList<T> :: elementAt( unsigned int index){
    if (empty()) return nullptr;
    Node<T>* current = head;
    for (int i = 0; i <= size(); i++){
        if (i == index){
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}






#endif