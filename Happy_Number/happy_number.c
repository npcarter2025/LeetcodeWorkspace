bool contains(int* arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return true;
    }
    return false;
}

bool isHappy(int n) {
    int *seen = NULL;
    int seenSize = 0;

    int copy = n;
    int squared = 0;
    int hold = n;

    //I'm stubborn. Let's make a helper function. this is SO much easier in Python.
    while (!contains(seen, seenSize, copy)) {

        int digit = hold % 10;
        squared += digit * digit;
        hold = hold / 10;
        if (hold == 0) {
            seen = realloc(seen, sizeof(int) * (seenSize + 1));
            seen[seenSize++] = copy;

            copy = squared;
            hold = squared;
            squared = 0;

        }
    }
    free(seen);
    return (copy == 1);

}
