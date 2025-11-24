/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {   
    *returnSize = numsSize;
    bool* result = (bool*)malloc((numsSize * sizeof(bool)));
    int remainder = 0;
    for (int i = 0; i < numsSize; i++) {

        remainder = (((remainder << 1) + nums[i]) % 5);

        result[i] = (remainder== 0);
    }

    return result;

}

int main(void) {
    int nums[] = {0,1,1,1,1,1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int returnSize = 0;
    bool* result = prefixesDivBy5(nums, numsSize, &returnSize);

    for(int i = 0; i < numsSize; i++) {
        printf("%d", nums[i]);
    }
    printf("\n");

    for(int i = 0; i < returnSize; i++) {
        printf("%s", result[i] ? "true" : "false");
    }
    printf("\n");

    free(result);
    return 0;
}