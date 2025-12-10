/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int elems = matSize * (*matColSize);

    printf("elems %d\n", elems);
    printf("matSize %d\n",matSize);
    printf("matColSize %d\n",matColSize[0]);
    printf("rows %d\n",r);
    printf("cols %d\n", c);


    if (matSize <= 0 || *matColSize <= 0 || elems != r * c || (matSize == r && matColSize[0] == c)) {
        *returnSize = matSize;

        *returnColumnSizes = (int*)malloc(matSize * sizeof(int));
        for (int i = 0; i < matSize; i++) {
            (*returnColumnSizes)[i] = matColSize[0]; 
        }
        return mat;
    }

    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c; 
    }

    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    int* temp = (int*)malloc(elems * sizeof(int));
    for (int i = 0; i < matSize; i ++) {
        for (int j = 0; j < matColSize[0]; j++) {
            temp[i * matColSize[0] + j] = mat[i][j];
        }
    }


    /*

    2d to 1d

    matrix[i * c + j] = mat[i][j]

    1d to 2d:
    matrix[r][c] = one_dim[]

    */
    *returnSize = r;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {

            matrix[i][j] = temp[i * c + j];



        }
    }

    free(temp);

    return matrix;
}