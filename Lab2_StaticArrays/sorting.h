#pragma once

#include "array.h"

void bubbleSort(int(&arr)[MAX_N], int size);
void insertionSort(int(&arr)[MAX_N], int size);
void selectionSort(int(&arr)[MAX_N], int size);
void shakerSort(int(&arr)[MAX_N], int size);
void mergeSort(int(&arr)[MAX_N], int(&temp)[MAX_N], int l, int r);