#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* convolution_1d(int* mat, int* kernel, int matSize, int kernelSize, int stride, int* returnSize) {
    int elems = (matSize - kernelSize) / stride + 1;
    //printf("elems %d", elems);
    // correlation Size: if matsize = 5, k = 3:
    if (matSize < kernelSize || stride <= 0 || elems <= 0) {
        *returnSize = 0;
        return NULL;
    }


    *returnSize = elems;

    int* convoluted = (int*)calloc(elems, sizeof(int));

    for (int i = 0; i < elems; i++) {
        for (int j = 0; j < kernelSize; j++) {
            convoluted[i] += mat[i * stride + j] * kernel[kernelSize - 1 - j];   
        }
    }
    return convoluted;
}

int main(int argc, char* argv[]) {

    int k_size;
    int mat_size;
    int stride;
    srand(time(NULL));

    if (argc < 3) {
        mat_size = 10;
        k_size = 3;
        stride = 1;

    } else {
        mat_size = atoi(argv[1]);
        k_size = atoi(argv[2]);
        stride = atoi(argv[3]);
    }

    int matrix[mat_size];
    int kernel[k_size];

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


    int* convoluted;
    int returnSize;


    convoluted = convolution_1d(matrix, kernel, mat_size, k_size, stride, &returnSize);


    printf("\nResult: ["); 
    for (int i = 0; i < returnSize; i++) {

        printf("%d", convoluted[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");


    free(convoluted);
    return 0;

}