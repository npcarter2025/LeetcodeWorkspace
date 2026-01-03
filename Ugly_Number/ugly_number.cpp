#include <stdio.h>
#include <stdlib.h>


// This was one of the most poorly-worded questions I've ever seen lol
// Basically, A Number is Ugly ONLY has Prime Factors 2, 3, & 5. 
// Disregard non-Prime Factors.

class Solution {
    public:
        static bool isUgly(int n) {
            // ugly
            if (n == 1) {
                return true;
            }
            if (n < 1) {
                return false;
            }
    
            while (n % 5 == 0) n /= 5;
            while (n % 3 == 0) n /= 3;
            while (n % 2 == 0) n /= 2;
    
            return n == 1;
        }
    };


int main(int argc, char* argv[]){
    int num;
    if (argc > 1) {
        num = atoi(argv[1]);
    } else {
        num = 15;
    }

    bool flag = Solution::isUgly(num);

    printf("flag == %d\n", flag);
    return 0;
}