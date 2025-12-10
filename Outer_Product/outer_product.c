#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* outer_product(int* vec1, int* vec2, int vecSize1, int vecSize2, int* returnSize, int** returnColumnSizes) {

    int elems = vecSize1 * vecSize2;
    if (elems <= 0) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = elems;

    *returnColumnSizes = (int*)malloc(vecSize1 * sizeof(int));
    for (int i = 0; i < vecSize1; i++) {
        (*returnColumnSizes)[i] = vecSize2;
    }


    int* matrix = (int*)calloc(elems, sizeof(int));

    for (int i = 0; i < vecSize1; i++) {

        for (int j = 0; j < vecSize2; j++) {

            matrix[i*vecSize2 + j] = vec1[i] * vec2[j];

        }
    }
    return matrix;
}



int main(int argc, char* argv[]){


    int* vec1;
    int* vec2;
    int vSize1;
    int vSize2;

    srand(time(NULL));


    if (argc < 3) {
        vSize1 = 3;
        vSize2 = 3;
    } else {
        vSize1 = atoi(argv[1]);
        vSize2 = atoi(argv[2]);
    }

    vec1 = (int*)malloc(vSize1 * sizeof(int));
    vec2 = (int*)malloc(vSize2 * sizeof(int));

    printf("\nVec1: \n[");
    for (int i = 0; i < vSize1; i++) {
        vec1[i] = rand() % 10;
        printf("%d", vec1[i]);
        if ( i < vSize1 - 1) {
            printf(", ");
        }
    }
    printf("]\n\nVec2: \n[");
    for (int i = 0; i < vSize2; i++) {
        vec2[i] = rand() % 10;
        printf("%d", vec2[i]);
        if ( i < vSize2 - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");







    int* result;
    int opSize;
    int* returnColumnSizes;

    result = outer_product(vec1, vec2, vSize1, vSize2, &opSize, &returnColumnSizes);

    printf("\nResult: \n["); 
    for (int i = 0; i < vSize1; i++) {

        //kernel[i] = (int*)malloc(k_size * sizeof(int));
        if (i > 0) {
            printf(" ");
        }
        printf("[");
        for (int j = 0; j < vSize2; j++) {
            //kernel[i][j] = (int)rand() % 10;
            printf("%d", result[i * vSize2 + j]);
            if (j < vSize2 - 1) {
                printf(", ");
            }
        }
        printf("]");
        if (i < vSize1 - 1) {
            printf(",\n");
        }
    }
    printf("]\n");

    free(vec1);
    free(vec2);
    free(result);
    free(returnColumnSizes);
    printf("\n");
    return 0;
}