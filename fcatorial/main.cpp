#include <iostream>
#include "Factorial.h"
#include "Factorial.cpp"
#include "Fibonachi.h"
#include "Fibonachi.cpp"
using namespace std;
/*
int factorial(int n){
    if (n == 1){
        return 1;
    }else{
        return n*factorial(n-1);
    }
}*/
int main() {
    
   int n = 6;
   for (int i =0 ; i <= n; i++){
        cout<<"fact de("<<i<<") = "<<Factorial::factorial(i)<<" |\n";
   }
    cout<<"---------------\n";
   for(int i = 0 ; i <= n; i++){
        cout<<"fib de("<<i<<") = "<<Fibonachi::fibonachi(i)<<" |\n";
   }
    

    return 0;
}