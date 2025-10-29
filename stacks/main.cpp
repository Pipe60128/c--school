#include "Stack.h"

int main () {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.print();
    cout << "El valor en top es: " << stack.pop() << endl;
    stack.print();
    return 0;
}