#include <map>
using namespace std;

class Solution {
public:
    map<int, int> memory;

    int fib_memoized(int num) {
        if (num == 1) {
            return 1;
        }
        if (num < 1) {
            return 0;
        }
        if (memory.count(num)) {
            return memory[num];
        }

        memory[num] = fib_memoized(num-1) + fib_memoized(num-2);
        return memory[num];
    }



    int fib(int n) {
        return fib_memoized(n);

    // SIMPLE RECURSIVE APPROACH
    //     if (n == 1) {
    //         return 1;
    //     }
    //     else if (n < 1) {
    //         return 0;
    //     }
    //     return fib(n-1) + fib(n-2);
    }


    // ITERATIVE SOLUTION
    int fib_iterative(int n) {
        if (n == 1) {
            return 1;
        }
        else if (n < 1) {
            return 0;
        }
        int a = 0; 
        int b = 1;
        int c = 0;
        for (int i = 2; i < n + 1; i++ ){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }  


};

