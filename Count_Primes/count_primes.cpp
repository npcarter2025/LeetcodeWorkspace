#include <stdio.h>
#include <stdlib.h>
#include <vector>

// make sure to run this with c++11 or it'll fail compilation:
// 
// g++ -std=c++11 count_primes.cpp -o dd && ./dd 10

class Solution {
    public:
        int countPrimes(int n) {
    
            if (n <= 1) return 0;
    
            int total = 0;
            std::vector<int> history(n-2, 1);
    
            // declare a vector of length(n-2) with all 1's
            // value 0 & 1 are NOT prime
            // index 0 corresponds to value 2
            // IE: n = 10: only need 8 spots
            // index < 0, 1, 2, 3, 4, 5, 6, 7 >
            // value < 2, 3, 4, 5, 6, 7, 8, 9 > <--- this is not actually in the Array. 
            // Everything is initialized to 1's
            // then we will invalidate values as we proceed.
            // At the end, we will count how many 1's are left.
    
    
            for (int index = 0; index < n-2; index++) {
                int currValue = index + 2;
                // if it's already been invalidated, we can just skip it.
                if (history[index] == 0) {
                    continue;
                }
    
                if (currValue * currValue >= n) {
                    break;
                }
    
                for (int multiple = currValue * currValue; multiple < n; multiple += currValue) {
                    history[multiple - 2] = 0;
                }
                   
            }
            for (int i : history) {
                total += i;
            }
    
    
    
            return total;
    
        }
    };



int main(int argc, char* argv[]) {

    int num;

    if (argc > 1) {
        num = atoi(argv[1]);
    } else {
        num = 20;
    }

    Solution s;
    int result = s.countPrimes(num);

    printf("result = %d\n", result);

    return 0;

    

}