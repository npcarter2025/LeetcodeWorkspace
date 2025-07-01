/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {
    int** array = (int**) malloc(imageSize * sizeof(int*));

    *returnColumnSizes = (int*) malloc(imageSize * sizeof(int));
    *returnSize = imageSize;

    for (int i = 0; i < imageSize; i++) {
        int cols = imageColSize[i];
        array[i] = (int*) malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;

        for (int j = 0; j < (cols + 1) / 2; j++) {
            int temp = image[i][j];
            array[i][j] = 1 ^ image[i][cols - 1 - j];
            array[i][cols - 1 - j] = 1 ^ temp;

        }
    }


    return array;

}

