#include <iostream>
#include "BST.h"
using namespace std;
int main() {
    BST<int> tree;
    tree.insert(8);
    tree.insert(12);
    tree.insert(17);
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(10);
    tree.insert(11);
    tree.insert(15);
    tree.insert(1);
    tree.print();
    tree.ancestors(4);
    
    tree.remove(2);
    tree.print();
    
    cout<<"postOrder"<<endl;
    tree.postOrder();
    cout<<"preOrder"<<endl;
    tree.preOrder();
    cout<<"intOrder"<<endl;
    tree.inOrder();
    tree.search(11);
    cout<<"_________________________________"<<endl;
    cout<<"|checando si esta vacio...      |\n| < "<<tree.isEmpty()<<" >                         |\n| 1 = vacio / 0 = no esta vacio |"<<endl;

    cout<<"_________________________________"<<endl;    
    cout<<"|calculando altura del arbol....|"<<endl;
    cout<<"|Altura: "<<tree.height()<<endl;
    cout<<"|_______________________________|"<<endl;

    cout<<"________________________________"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|nivel: "<<tree.whatLevelAmI(12)<<endl;

    cout<<"|_______________________________|"<<endl;
    tree.clear();
    cout<<"_________________________________"<<endl;
    cout<<"|checando si esta vacio...      |\n| < "<<tree.isEmpty()<<" >                         |\n| 1 = vacio / 0 = no esta vacio |"<<endl;
    cout<<"|_______________________________|"<<endl;

    cout<<"________________________________"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|nivel: "<<tree.whatLevelAmI(12)<<endl;

    cout<<"|_______________________________|"<<endl;
    return 0;
}