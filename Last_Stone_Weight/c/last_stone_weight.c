#include <stdbool.h>
/*I just translated my C++ version to C.
* I might optimize this later on
*/
int lastStoneWeight(int* stones, int stonesSize) {
    int arr[stonesSize];
    while (stonesSize >= 2) {
        // just need to grab the largest 2 values
        int stone1, ind1;
        int stone2, ind2;
        stone1 = -1; //stone1 is supposed to be the biggest
        stone2 = -1; //stone2 <= stone1
        ind1 = -1;
        ind2 = -1;
        for (int i = 0; i < stonesSize; i++ ) {
            if (stone1 < stones[i]) {
                ind2 = ind1;
                stone2 = stone1;
                stone1 = stones[i];
                ind1 = i;
            } else if (stones[i] > stone2) {
                stone2 = stones[i];
                ind2 = i;
            }
        }
        // we now have the 2 largest stones, and their indices from the array.
        bool Flag = (stone1 == stone2);

        int newStoneSize = 0;
        int newArr[stonesSize];
        for (int j = 0; j < stonesSize; j++ ) {
            if (j == ind1 || j == ind2) {
                continue;
            }
            newArr[newStoneSize++] = stones[j];
        }
        if (!Flag) {
            newArr[newStoneSize++] = stone1 - stone2;
        }
        for (int k = 0; k < newStoneSize; k++) {
            stones[k] = newArr[k];
        }
        stonesSize = newStoneSize;
    }
    return (stonesSize == 0) ? 0 : stones[0];
}


