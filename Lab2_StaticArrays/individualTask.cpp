#include "individualTask.h"


int replaceMultipleOfThree(int(&arr)[MAX_N], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            arr[i] = 0;
            count++;
        }
    }

    return count;
}