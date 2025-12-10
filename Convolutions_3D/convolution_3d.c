#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int*** convolution_3d(int*** mat, int*** kernel, int matSize, int kernelSize, int* returnSize, int*** returnColumnSizes) {
    int height = matSize - kernelSize + 1;
    int width = matSize - kernelSize + 1;
    int depth = matSize - kernelSize + 1;
    int elems = height * width * depth;

    // correlation Size: if matsize = 5, k = 3:
    if (matSize < kernelSize || height <= 0 || width <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    *returnSize = height;

    *returnColumnSizes = (int**)malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        (*returnColumnSizes)[i] = (int*)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            (*returnColumnSizes)[i][j] = depth;
        }

    }


    int*** convoluted = (int***)malloc(height * sizeof(int**));
    for (int i = 0; i < height; i++ ) {
        
        convoluted[i] = (int**)malloc(width * sizeof(int*));
        for (int j = 0; j < width; j++) {
            convoluted[i][j] = (int*)calloc(depth, sizeof(int));
        }
    }

    for (int a = 0; a < height; a++) {
        for (int b = 0; b < width; b++) {
            for (int c = 0; c < depth; c++)



            //Subsection
            for (int x = 0; x < kernelSize; x++ ) {
                for (int y = 0; y < kernelSize; y++) {
                    for (int z = 0; z < kernelSize; z++) {
                        convoluted[a][b][c] += mat[x+a][y+b][z+c] * kernel[kernelSize - 1 - x][kernelSize - 1 - y][kernelSize - 1 - z];
                    }
                }
            }
        }
    }

    return convoluted;
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

    int*** matrix = (int***)malloc(mat_size * sizeof(int**));
    int*** kernel = (int***)malloc(k_size * sizeof(int**));

    printf("\n3D Convolution\n\n");
    printf("Matrix: \n[");
    for (int i = 0; i < mat_size; i++) {

        matrix[i] = (int**)malloc(mat_size * sizeof(int*));

        for (int j = 0; j < mat_size; j++) {
            matrix[i][j] = (int*)malloc(mat_size * sizeof(int));
        }

        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < mat_size; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("[");
            for (int k = 0; k < mat_size; k++) {
                matrix[i][j][k] = (int)rand() % 10;
                printf("%d", matrix[i][j][k]);
                if (k < mat_size - 1) {
                    printf(", ");
                }
            }
            printf("]");
            if (j < mat_size - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < mat_size - 1) {
            printf(",\n");
        }
    }  
    printf("]\n\nKernel: \n["); 
    for (int i = 0; i < k_size; i++) {

        kernel[i] = (int**)malloc(k_size * sizeof(int*));


        for (int j = 0; j < k_size; j++) {
            kernel[i][j] = (int*)malloc(k_size * sizeof(int));

        }

        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < k_size; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("[");
            for (int k = 0; k < k_size; k++) {
                kernel[i][j][k] = (int)rand() % 10;
                printf("%d", kernel[i][j][k]);
                if (k < k_size - 1) {
                    printf(", ");
                }
            }
            printf("]");
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


    int*** convoluted;
    int returnSize;
    int** returnColumnSizes;

    convoluted = convolution_3d(matrix, kernel, mat_size, k_size, &returnSize, &returnColumnSizes);

    printf("\nResult: \n["); 
    for (int i = 0; i < returnSize; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < returnSize; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("[");
            for (int k = 0; k < returnColumnSizes[i][j]; k++) {
                printf("%d", convoluted[i][j][k]);
                if (k < returnColumnSizes[i][j] - 1) {
                    printf(", ");
                }
            }
            printf("]");
            if (j < returnSize - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",\n");
        }
    }
    printf("]\n\n");




    // FREEEEE EVERYTHINGGGGGGG
    for (int i = 0; i < mat_size; i++) {
        for (int j = 0; j < mat_size; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < k_size; i++) {
        for (int j = 0; j < k_size; j++) {
            free(kernel[i][j]);
        }
        free(kernel[i]);
    }
    free(kernel);
    


    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnSize; j++) {
            free(convoluted[i][j]);
        }
        free(convoluted[i]);
    }
    free(convoluted);
    for (int i = 0; i < returnSize; i++) {
        free(returnColumnSizes[i]);
    }
    free(returnColumnSizes);

    return 0;




}