#pragma once

#include "array.h"

void findExtremum(const int(&arr)[MAX_N], int size, int& min, int& max);
int findIndices(const int(&arr)[MAX_N], int size, int average, int(&indices)[MAX_N]);
int findLess(const int(&arr)[MAX_N], int size, int a);
int findMore(const int(&arr)[MAX_N], int size, int b);
int binarySearchLess(const int(&arr)[MAX_N], int size, int a);
int binarySearchMore(const int(&arr)[MAX_N], int size, int b);
int binarySearch(const int(&arr)[MAX_N], int size, int target);
int linearSearch(const int(&arr)[MAX_N], int size, int target);
void exchange(int(&arr)[MAX_N], int one, int two);
