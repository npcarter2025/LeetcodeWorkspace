#include <stdio.h>
#include <stdlib.h>
#include <time.h>


float* mat_mul(float* A, float* B, int m, int k, int n){

    float* C = (float*)calloc(m * n, sizeof(float));

    for (int x = 0; x < m; x++ ) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < k; z++) {

                C[x*n + y] += A[x * k + z] * B[z * n+ y];



            }
        }
    }
    return C;

}


int main() {
    int M = 4; 
    int K = 3;
    int N = 3;

    // Seed the random number generator with current time
    srand(time(NULL));

    float* A = (float*)malloc(M * K * sizeof(float));
    float* B = (float*)malloc(K * N * sizeof(float));

    for (int i = 0; i < M * K; i++) {
        A[i] = (float)rand() / RAND_MAX * 10.0f;  
    }
    for (int i = 0; i < K * N; i++) {
        B[i] = (float)rand() / RAND_MAX * 10.0f; 
    }

    float* C;

    C = mat_mul(A, B, M, K, N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", C[i * N + j]);
        }
        printf("\n");
    }


    free(A);
    free(B);
    free(C);

    return 0;
}