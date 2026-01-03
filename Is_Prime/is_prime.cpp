#include <stdio.h>
#include <stdlib.h>



bool is_prime(int n) {

    if (n == 1 || n == 2) {
        return true;
    }

    for (int i = 3; i*i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    } 
    return true;
}


int main(int argc, char* argv[]) {

    
    int num;

    if (argc > 1) {
        num = atoi(argv[1]);
    } else {
        num = 5;
    }

    bool flag;

    flag = is_prime(num);

    printf("flag = %d\n", flag);

    return 0;

}