/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 * 
 */

#include <stdlib.h>
#include <stdio.h>


int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {

    if (m * n != originalSize) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int rows = m;
    int cols = n;

    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }
    *returnSize = rows;


    int** matrix = (int**)malloc(m * sizeof(int*));

    for (int r = 0; r < m; r++) {

        matrix[r] = (int*)calloc(n, sizeof(int));

        for (int c = 0; c < n; c++) {

            matrix[r][c] = original[r*n + c];
        }

    }
    return matrix;
    
}

int main() {

    int original[4] = {1,2,3,4};
    int* ptr = original;
    int ogSize = 4;
    int m = 2;
    int n = 2;
    int retSize;
    int* retColSizes;

    int** twoDmat;
    
    twoDmat = construct2DArray(ptr, ogSize, m, n, &retSize, &retColSizes);

    for (int i = 0; i < m; i++) {
        printf("[");
        for (int j = 0; j < n; j++) {
            printf("%d", twoDmat[i][j]);
            if (j < n - 1) printf(", ");
        }
        printf("]\n");
    }



}