#include "search.h"
#include <utility>

void findExtremum(const int(&arr)[MAX_N], int size, int& min, int& max) {
    min = arr[0];
    max = arr[0];

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}

int findIndices(const int(&arr)[MAX_N], int size, int average, int(&indices)[MAX_N]) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == average) {
            indices[count] = i;
            count++;
        }
    }
    return count;
}

int findLess(const int(&arr)[MAX_N], int size, int a) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < a) {
            count++;
        }
    }
    return count;
}

int findMore(const int(&arr)[MAX_N], int size, int b) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > b) {
            count++;
        }
    }
    return count;
}

int binarySearchLess(const int(&arr)[MAX_N], int size, int a) {
    int l = 0;
    int r = size - 1;
    int res = size;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= a) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return res;
}

int binarySearchMore(const int(&arr)[MAX_N], int size, int b) {
    int l = 0;
    int r = size - 1;
    int res = size;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] > b) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return size - res;
}

int binarySearch(const int(&arr)[MAX_N], int size, int target) {
    int l = 0;
    int r = size - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return -1;
}

int linearSearch(const int(&arr)[MAX_N], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void exchange(int(&arr)[MAX_N], int one, int two) {
    std::swap(arr[one], arr[two]);
}