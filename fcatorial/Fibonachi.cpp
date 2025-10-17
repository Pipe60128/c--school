#include "Fibonachi.h"
#include <iostream>
using namespace std;
class Fibonachi{
    public:

    static unsigned int fibonachi(unsigned int n){
        if (n == 0 ) {
            return 0;
        }else if ( n == 1) {
            return 1;
        } else {
            return fibonachi(n - 1) + fibonachi(n - 2);
        }
    }

};
