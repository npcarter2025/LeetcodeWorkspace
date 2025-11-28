int maximumDifference(int* nums, int numsSize) {
    int maxDiff = -1; 

    int min = nums[0];

    for (int i = 1; i < numsSize; i++) {
        int diff = nums[i]-min;

        if (nums[i] < min) {

            min = nums[i]; 
        } else if (diff > 0 && diff > maxDiff) {
            maxDiff = diff;

        }
    }
    return maxDiff;
}