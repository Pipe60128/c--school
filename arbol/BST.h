#ifndef BST_H
#define BST_H
#include "Node.h"

template <typename T>
class BST{
    private:
        Node<T>* root;
        bool search(Node<T>* root, const T& v)const;
        void clear(Node<T>* root);
        int height(Node<T>* root);
        void print(Node<T>* root, int nr, int nl);
        void visit(Node<T>* node) const;
        void inOrder(Node<T>* node) const;
        void preOrder(Node<T>* node) const;
        void postOrder(Node<T>* node) const;
        Node<T>* removeNode(Node<T>* node, const T& v);
        bool ancestors(Node<T>* node, const T& v);
    public:
        BST();
        ~BST();
        bool isEmpty();
        void print();
        void clear();
        int height();
        int whatLevelAmI(const T& v);
        void insert(const T& v);
        bool search(const T& v) const;
        void inOrder() const;
        void preOrder() const;
        void postOrder() const;
        void remove(const T& v);
        void ancestors(const T& v);
};
#include "BST.tpp"
#endif //BST_H