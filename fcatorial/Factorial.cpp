#include "Factorial.h"
#include <iostream>
using namespace std;
class Factorial{
    public:

    static unsigned int factorial(unsigned int n){
        if (n == 0 || n == 1) {
            return 1;
        } else {
            return n + factorial(n - 1);
        }
    }

};
