#ifndef STACK_H
#define STACK_H
#include "Node.h"

template <typename T>
class Stack{
    private:
        Node<T>* topNode;
        unsigned int count;
    public:
        Stack(): topNode(nullptr), count(0) {}
        ~Stack(){
            clear();
        }
        void clear();
        void push(const T& v);
        T pop(); // theque
        T top(); // inque
        bool isEmpty() const;
        bool isFull();
        void print() const;

};

#include "Stack.tpp"
#endif //STACK_H