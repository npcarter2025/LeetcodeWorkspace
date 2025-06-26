//||=====XOR BITWISE APPROACH=======||
int missingNumber(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < numsSize + 1; i++) {
        result ^= i;
    }
    for (int j = 0; j < numsSize; j++) {
        result ^= nums[j];
    }
    return result;
}

