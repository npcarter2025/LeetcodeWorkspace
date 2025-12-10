#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** cross_correlation(int** mat, int** kernel, int matSize, int kernelSize, int* returnSize, int** returnColumnSizes) {
    int height = matSize - kernelSize + 1;
    int width = matSize - kernelSize + 1;
    int elems = height * width;

    // correlation Size: if matsize = 5, k = 3:
    if (matSize < kernelSize || height <= 0 || width <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }


    *returnSize = height;

    *returnColumnSizes = (int*)malloc(height * sizeof(int));
    for (int i = 0; i < height; i++) {
        (*returnColumnSizes)[i] = width;
    }


    int** correlated = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++ ) {
        correlated[i] = (int*)calloc(width, sizeof(int));
    }

    for (int a = 0; a < height; a++) {
        for (int b = 0; b < width; b++) {


            //Subsection
            for (int x = 0; x < kernelSize; x++ ) {
                for (int y = 0; y < kernelSize; y++) {
                    correlated[a][b] += mat[x+a][y+b] * kernel[x][y];
                }
            }
        }
    }

    return correlated;
}

int main(int argc, char* argv[]) {

    
    int mat_size;
    int k_size;
    srand(time(NULL));

    if (argc < 3) {
        mat_size = 4;
        k_size = 2;

    } else {
        mat_size = atoi(argv[1]);
        k_size = atoi(argv[2]);
    }

    int** matrix = (int**)malloc(mat_size * sizeof(int*));
    int** kernel = (int**)malloc(k_size * sizeof(int*));


    printf("Matrix: \n[");
    for (int i = 0; i < mat_size; i++) {

        matrix[i] = (int*)malloc(mat_size * sizeof(int));

        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < mat_size; j++) {
            matrix[i][j] = (int)rand() % 10;
            printf("%d", matrix[i][j]);
            if (j < mat_size - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < mat_size - 1) {
            printf(",\n");
        }
    }  
    printf("]\nKernel: \n["); 
    for (int i = 0; i < k_size; i++) {

        kernel[i] = (int*)malloc(k_size * sizeof(int));
        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < k_size; j++) {
            kernel[i][j] = (int)rand() % 10;
            printf("%d", kernel[i][j]);
            if (j < k_size - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < k_size - 1) {
            printf(",\n");
        }
    }
    printf("]\n");


    int** correlated;
    int returnSize;
    int* returnColumnSizes;

    correlated = cross_correlation(matrix, kernel, mat_size, k_size, &returnSize, &returnColumnSizes);

    printf("\nResult: \n["); 
    for (int i = 0; i < returnSize; i++) {

        //kernel[i] = (int*)malloc(k_size * sizeof(int));
        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < returnSize; j++) {
            //kernel[i][j] = (int)rand() % 10;
            printf("%d", correlated[i][j]);
            if (j < returnSize - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",\n");
        }
    }
    printf("]\n");




    // FREEEEE EVERYTHINGGGGGGG
    for (int i = 0; i < mat_size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < k_size; i++) {
        free(kernel[i]);
    }
    free(kernel);
    


    for (int i = 0; i < returnSize; i++) {
        free(correlated[i]);
    }
    free(correlated);
    free(returnColumnSizes);

    return 0;




}