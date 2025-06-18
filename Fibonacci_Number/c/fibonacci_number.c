// ITERATIVE Solution

int fib(int n) {
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

