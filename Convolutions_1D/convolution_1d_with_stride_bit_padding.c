#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* convolution_1d(int* mat, int* kernel, int matSize, int kernelSize, int stride, int padding, int paddingMode, int* returnSize) {
    int mode = (paddingMode == 0 || paddingMode == 1) ? paddingMode : 0;
    // mode 0 = zeropadding
    // mode 1 = mirror the edge elem
    
    int elems = (matSize + (2 * padding) - kernelSize) / stride + 1;
    //printf("elems %d", elems);
    // correlation Size: if matsize = 5, k = 3:
    if (matSize < kernelSize || stride <= 0 || elems <= 0 || padding < 0) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = elems;

    int* convoluted = (int*)calloc(elems, sizeof(int));


    for (int i = 0; i < elems; i++) {
        for (int j = 0; j < kernelSize; j++) {

            int index = i * stride - padding + j; 
            if (index >= 0 && index < matSize) {
                convoluted[i] += mat[index] * kernel[kernelSize - 1 - j];
            } else {
                if (mode == 1) {
                    if (index < 0) {
                        convoluted[i] += mat[0] * kernel[kernelSize - 1 - j];
                    } else { // index is already at the end
                        convoluted[i] += mat[matSize - 1] * kernel[kernelSize - 1 - j];
                    }

                }
            }

        }
    }
    return convoluted;
}

int main(int argc, char* argv[]) {

    int k_size;
    int mat_size;
    int stride;
    int padding;
    int paddingMode;
    srand(time(NULL));

    if (argc < 6) {
        mat_size = 10;
        k_size = 3;
        stride = 1;
        padding = 0;
        paddingMode = 0;

    } else {
        mat_size = atoi(argv[1]);
        k_size = atoi(argv[2]);
        stride = atoi(argv[3]);
        padding = atoi(argv[4]);
        paddingMode = atoi(argv[5]);
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


    convoluted = convolution_1d(matrix, kernel, mat_size, k_size, stride, padding, paddingMode, &returnSize);


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