#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"


template<typename T>
class LinkedList{
    private:
        Node<T>* head;
        unsigned int n; 
    public:
        LinkedList();
        ~LinkedList();
        unsigned int size() const;
        bool empty() const; 
        void clear();
        void pushFront(const T& value);
        void pushBack(const T& value);
        bool insert(unsigned int index, const T& value);
        bool remove( const T& value);
        T* elementAt(unsigned int index);
        void print();


};

#include "linkedList.tpp"
#endif //LINKEDLIST_H