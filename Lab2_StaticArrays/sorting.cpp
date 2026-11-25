#include "sorting.h"
#include <utility>

void bubbleSort(int(&arr)[MAX_N], int size) {
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int(&arr)[MAX_N], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void selectionSort(int(&arr)[MAX_N], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

void shakerSort(int(&arr)[MAX_N], int size) {
    int l = 0;
    int r = size - 1;
    int lastSwap;

    while (l < r) {
        lastSwap = l;
        for (int i = l; i < r; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                lastSwap = i;
            }
        }
        r = lastSwap;

        lastSwap = r;
        for (int i = r; i > l; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                lastSwap = i;
            }
        }

        l = lastSwap;
    }
}

void mergeIt(int(&arr)[MAX_N], int(&temp)[MAX_N], int l, int mid, int r) {
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(int(&arr)[MAX_N], int(&temp)[MAX_N], int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + (r - l) / 2;
    mergeSort(arr, temp, l, mid);
    mergeSort(arr, temp, mid + 1, r);

    mergeIt(arr, temp, l, mid, r);
}