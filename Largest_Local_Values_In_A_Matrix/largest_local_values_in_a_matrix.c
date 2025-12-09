/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    
    int N = gridSize;
    int result_dim = N - 2;

    *returnSize = *gridColSize - 2;

    *returnColumnSizes = (int*)malloc(result_dim * sizeof(int));
    for (int i = 0; i < result_dim; i++) {
        (*returnColumnSizes)[i] = result_dim;
    }    
    int** maxLocal = (int**)malloc((gridSize - 2) * sizeof(int*));

    for (int i = 0; i < gridSize - 2; i++) {
        maxLocal[i] = (int*)calloc(*returnSize, sizeof(int));
    }

    for (int a = 0; a < *returnSize; a++) {
        for (int b = 0; b < *returnSize; b++) {

            for (int x = a; x < a + 3; x++) {
                for (int y = b; y < b + 3; y++) {
                    maxLocal[a][b] = (grid[x][y] > maxLocal[a][b]) ? grid[x][y] : maxLocal[a][b];

                }
            } 
        }
    }
    return maxLocal;



}

int main() {

    printf("test 1 4x4 matrix \n");
    int gridSize = 4;
    int gridColS = 4;
    int* gridColSize = &gridColS;
    int returnSize;
    int* returnColSizes;

    int** grid = (int**)malloc(4 * sizeof(int*));
    for (int i = 0; i < 4; i++) {
        grid[i] = (int*)calloc(4, sizeof(int));
    }
    // Initialize test matrix 1: [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    int test1[4][4] = {{9,9,8,1},{5,6,2,6},{8,2,6,4},{6,2,2,2}};
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            grid[x][y] = test1[x][y];
        }
    }

    int** largest = largestLocal(grid, gridSize, gridColSize, &returnSize, &returnColSizes);

    // Print results
    printf("Result matrix (%dx%d):\n", returnSize, returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnSize; j++) {
            printf("%d ", largest[i][j]);
        }
        printf("\n");
    }
    printf("test 1 complete \n");

    // Free memory from test 1
    for (int i = 0; i < 4; i++) {
        free(grid[i]);
    }
    free(grid);
    for (int i = 0; i < returnSize; i++) {
        free(largest[i]);
    }
    free(largest);
    free(returnColSizes);


    printf("test 2 5x5 matrix\n");

    // Initialize test matrix 2: [[1,1,1,1,1],[1,1,1,1,1],[1,1,2,1,1],[1,1,1,1,1],[1,1,1,1,1]]
    gridSize = 5;
    gridColS = 5;
    gridColSize = &gridColS;
    
    grid = (int**)malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; i++) {
        grid[i] = (int*)calloc(5, sizeof(int));
    }
    int test2[5][5] = {{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            grid[x][y] = test2[x][y];
        }
    }

    largest = largestLocal(grid, gridSize, gridColSize, &returnSize, &returnColSizes);

    // Print results
    printf("Result matrix (%dx%d):\n", returnSize, returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnSize; j++) {
            printf("%d ", largest[i][j]);
        }
        printf("\n");
    }
    printf("test 2 complete \n");

    // Free memory from test 2
    for (int i = 0; i < 5; i++) {
        free(grid[i]);
    }
    free(grid);
    for (int i = 0; i < returnSize; i++) {
        free(largest[i]);
    }
    free(largest);
    free(returnColSizes);

    return 0;
}