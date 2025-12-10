#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mat_mul(float* A, float* B, float** C, int m, int k, int n){

    *C = (float*)calloc(m * n, sizeof(float));

    for (int x = 0; x < m; x++ ) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < k; z++) {

                (*C)[x*n + y] += A[x * k + z] * B[z * n+ y];



            }
        }
    }
    return;

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
        A[i] = (float)rand() / RAND_MAX * 10.0f;  // Generate random floats 0.0-10.0
    }
    for (int i = 0; i < K * N; i++) {
        B[i] = (float)rand() / RAND_MAX * 10.0f;  // Generate random floats 0.0-10.0
    }

    float* C; // = (float*)calloc(M * N,  sizeof(float));

    mat_mul(A, B, &C, M, K, N);

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