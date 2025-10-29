#include <iostream>
using namespace std;
#include "linkedList.h"


int main() {
    LinkedList<int> list; 
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(4);
    list.pushBack(5);
    list.print();
    list.insert(3,1);
    list.print();
    list.pushFront(2);
    list.print();
    int s = list.size();
    cout<<"The size of this linked list it is "<<s<<endl;
    bool result = list.remove(2);
    if (!result) cout<<"none element removed"<<endl;
    list.print();
    int* valor = list.elementAt(3);
    cout<< *valor<<endl;
    list.clear();
    list.print();
    int n = list.size();
    cout<<"The size of this linked list it is "<<n<<endl;
    return 0;
}
