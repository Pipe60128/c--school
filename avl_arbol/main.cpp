// Marlon y Felipe 
#include <iostream>
#include "AVLTree.h"

using namespace std;
int main() {
    AVLTree<int> avl;
    avl.insert(8);
    avl.insert(6);
    avl.insert(10);
    avl.insert(9);
    avl.insert(12);
    avl.print();
    cout<<"---------------------"<<endl;
    avl.insert(15);
    avl.print();
    avl.remove(8);
    cout<<"---------------------"<<endl;
    avl.print();
    avl.search(25);
    

    return 0;

}
