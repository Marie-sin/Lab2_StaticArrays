#include "array.h"
#include <iostream>
#include <random>

void fillArray(int(&arr)[MAX_N], int size) {
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(-99, 99);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
}

void printArray(const int(&arr)[MAX_N], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

void copyArray(const int(&source)[MAX_N], int(&final)[MAX_N], int size) {
    for (int i = 0; i < size; i++) {
        final[i] = source[i];
    }
}