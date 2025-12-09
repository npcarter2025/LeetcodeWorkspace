#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* cross_correlation(int* mat, int* kernel, int matSize, int kernelSize, int* returnSize) {

    // correlation Size: if matsize = 5, k = 3:
    if (matSize < kernelSize) {
        *returnSize = 0;
        return NULL;
    }

    int elems = matSize - kernelSize + 1;

    *returnSize = elems;

    int* correlated = (int*)malloc(elems * sizeof(int));

    for (int i = 0; i < elems; i++) {
        for (int j = 0; j < kernelSize; j++) {

            correlated[i] += mat[i + j] * kernel[j];
        }


    }
    return correlated;




}

int main(int argc, char* argv[]) {

    int k_size;
    int mat_size;
    srand(time(NULL));

    if (argc < 3) {
        mat_size = 10;
        k_size = 3;

    } else {
        mat_size = atoi(argv[1]);
        k_size = atoi(argv[2]);
    }

    int matrix[mat_size];
    int kernel[k_size];
    int* m = matrix;
    int* k = kernel;

    printf("Matrix: [");
    for (int i = 0; i < mat_size; i++) {
        matrix[i] = (int)rand() % 10;
        printf("%d", matrix[i]);
        if (i < mat_size - 1) {
            printf(", ");
        }
    }  
    printf("]\nKernel: ["); 
    for (int i = 0; i < k_size; i++) {
        kernel[i] = (int)rand() % 10;
        printf("%d", kernel[i]);
        if (i < k_size - 1) {
            printf(", ");
        }
    }
    printf("]\n");


    int* correlated;
    int returnSize;

    correlated = cross_correlation(matrix, kernel, mat_size, k_size, &returnSize);


    printf("\nResult: ["); 
    for (int i = 0; i < returnSize; i++) {

        printf("%d", correlated[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");


    free(correlated);
    return 0;




}