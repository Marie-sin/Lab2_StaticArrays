#pragma once

const int MAX_N = 100;

void fillArray(int(&arr)[MAX_N], int size);
void printArray(const int(&arr)[MAX_N], int size);
void copyArray(const int(&source)[MAX_N], int(&final)[MAX_N], int size);