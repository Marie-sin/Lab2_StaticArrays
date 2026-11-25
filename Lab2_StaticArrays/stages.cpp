#include "stages.h"
#include "sorting.h"
#include "search.h"
#include "individualTask.h"

#include <iostream>
#include <chrono>
#include <cmath>

void runStage3(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 3 ====\n\n";

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    //bubble sort
    int bubbleArray[MAX_N];
    copyArray(arr, bubbleArray, size);

    t1 = std::chrono::steady_clock::now();
    bubbleSort(bubbleArray, size);
    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nBubble-sorted array:\n";
    printArray(bubbleArray, size);
    std::cout << "Sorting took: " << ns << " ns\n";

    //insertion sort
    int insertionArray[MAX_N];
    copyArray(arr, insertionArray, size);

    t1 = std::chrono::steady_clock::now();
    insertionSort(insertionArray, size);
    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nInsertion-sorted array:\n";
    printArray(insertionArray, size);
    std::cout << "Sorting took: " << ns << " ns\n";

    //selection sort
    int selectionArray[MAX_N];
    copyArray(arr, selectionArray, size);

    t1 = std::chrono::steady_clock::now();
    selectionSort(selectionArray, size);
    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nSelection-sorted array:\n";
    printArray(selectionArray, size);
    std::cout << "Sorting took: " << ns << " ns\n";

    //shaker sort
    int shakerArray[MAX_N];
    copyArray(arr, shakerArray, size);

    t1 = std::chrono::steady_clock::now();
    shakerSort(shakerArray, size);
    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nShaker-sorted array:\n";
    printArray(shakerArray, size);
    std::cout << "Sorting took: " << ns << " ns\n";

    //merge sort
    int mergeArray[MAX_N];
    int temp[MAX_N];
    copyArray(arr, mergeArray, size);

    t1 = std::chrono::steady_clock::now();
    mergeSort(mergeArray, temp, 0, size - 1);
    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nMerge-sorted array:\n";
    printArray(mergeArray, size);
    std::cout << "Sorting took: " << ns << " ns\n\n";
}

void runStage4(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 4 ====\n\n";

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    int min;
    int max;

    //поиск в неотсортированном массиве
    t1 = std::chrono::steady_clock::now();
    findExtremum(arr, size, min, max);
    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "Minimum: " << min << "\n";
    std::cout << "Maximum: " << max << "\n";
    std::cout << "Finding min and max in an UNSORTED array took: "
        << ns << " ns\n\n";

    //создаём отсортированную копию
    int sortedArray[MAX_N];
    int temp[MAX_N];

    copyArray(arr, sortedArray, size);
    mergeSort(sortedArray, temp, 0, size - 1);

    //поиск в отсортированном массиве
    t1 = std::chrono::steady_clock::now();
    min = sortedArray[0];
    max = sortedArray[size - 1];
    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "Minimum: " << min << "\n";
    std::cout << "Maximum: " << max << "\n";
    std::cout << "Finding min and max in a SORTED array took: "
        << ns << " ns\n\n";
}

void runStage5(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 5 ====\n\n";

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    int min;
    int max;

    //находим минимум и максимум
    findExtremum(arr, size, min, max);

    int average = static_cast<int>(
        std::round((min + max) / 2.0)
        );

    int indices[MAX_N];
    int count;

    //поиск в неотсортированном массиве
    t1 = std::chrono::steady_clock::now();
    count = findIndices(arr, size, average, indices);
    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "Average between min and max: " << average << "\n";
    std::cout << "Number of elements equal to average: " << count << "\n\n";
    std::cout << "Finding elements in an unsorted array took: "
        << ns << " ns\n";
    std::cout << "Indices in an UNSORTED array: ";

    for (int i = 0; i < count; i++) {
        std::cout << indices[i] << " ";
    }

    std::cout << "\n\n";

    //создаём отсортированную копию
    int sortedArray[MAX_N];
    int temp[MAX_N];

    copyArray(arr, sortedArray, size);
    mergeSort(sortedArray, temp, 0, size - 1);

    //поиск в отсортированном массиве
    t1 = std::chrono::steady_clock::now();
    count = findIndices(sortedArray, size, average, indices);
    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
        t2 - t1
    ).count();

    std::cout << "Finding elements in a sorted array took: "
        << ns << " ns\n";
    std::cout << "Indices in a SORTED array: ";

    for (int i = 0; i < count; i++) {
        std::cout << indices[i] << " ";
    }

    std::cout << "\n\n";
}

void runStage6(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 6 ====\n\n";

    int a;
    int b;

    std::cout << "Enter number a: ";
    std::cin >> a;
    std::cout << "Enter number b: ";
    std::cin >> b;

    //cоздаём отсортированную копию
    int sortedArray[MAX_N];
    int temp[MAX_N];

    copyArray(arr, sortedArray, size);
    mergeSort(sortedArray, temp, 0, size - 1);

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    //линейный поиск
    t1 = std::chrono::steady_clock::now();

    int small = findLess(sortedArray, size, a);
    int big = findMore(sortedArray, size, b);

    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "\nNumber of elements smaller than " << a << ": " << small;
    std::cout << "\nNumber of elements bigger than " << b << ": " << big;
    std::cout << "\n\nFinding elements using linear search took: "
        << ns << " ns\n";

    //бинарный поиск
    t1 = std::chrono::steady_clock::now();

    small = binarySearchLess(sortedArray, size, a);
    big = binarySearchMore(sortedArray, size, b);

    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    std::cout << "Number of elements smaller than " << a << ": " << small;
    std::cout << "\nNumber of elements bigger than " << b << ": " << big;
    std::cout << "\nFinding elements using binary search took: "
        << ns << " ns\n\n";
}

void runStage7(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 7 ====\n\n";

    int num;
    const int repeats = 100000;
    int binaryIndex;
    int linearIndex;

    std::cout << "Enter number for a search: ";
    std::cin >> num;

    //создаём отсортированную копию
    int sortedArray[MAX_N];
    int temp[MAX_N];

    copyArray(arr, sortedArray, size);
    mergeSort(sortedArray, temp, 0, size - 1);

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    //бинарный поиск
    t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < repeats; i++) {
        binaryIndex = binarySearch(sortedArray, size, num);
    }

    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    double binaryAverage = static_cast<double>(ns) / repeats;

    std::cout << "Index of " << num << " is: " << binaryIndex;
    std::cout << "\nBinary search took: " << binaryAverage << " ns\n";

    //линейный поиск
    t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < repeats; i++) {
        linearIndex = linearSearch(sortedArray, size, num);
    }

    t2 = std::chrono::steady_clock::now();
    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    double linearAverage = static_cast<double>(ns) / repeats;

    std::cout << "Index of " << num << " is: " << linearIndex;
    std::cout << "\nLinear search took: " << linearAverage << " ns\n\n";
}

void runStage8(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 8 ====\n\n";

    int one;
    int two;
    const int repeats = 100000;
    int newArray[MAX_N];

    std::cout << "Enter the first Index (0 - "
        << size - 1 << "): ";
    std::cin >> one;

    std::cout << "Enter the second Index (0 - "
        << size - 1 << "): ";
    std::cin >> two;

    if (one < 0 || one >= size || two < 0 || two >= size) {
        std::cout << "\nError: Invalid index!\n";
        return;
    }

    std::cout << "Original array:\n";
    printArray(arr, size);

    copyArray(arr, newArray, size);

    std::chrono::steady_clock::time_point t1;
    std::chrono::steady_clock::time_point t2;
    long long ns;

    t1 = std::chrono::steady_clock::now();

    for (int i = 0; i < repeats; i++) {
        exchange(newArray, one, two);
    }

    t2 = std::chrono::steady_clock::now();

    ns = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

    double exchangeAverage = static_cast<double>(ns) / repeats;

    //делаем ещё один обмен, чтобы показать изменённый массив
    exchange(newArray, one, two);

    std::cout << "New array:\n";
    printArray(newArray, size);

    std::cout << "Exchange took: " << exchangeAverage << " ns\n\n";
}

void runStage9(const int(&arr)[MAX_N], int size) {
    std::cout << "\n ==== STAGE 9 ====\n\n";

    int taskArray[MAX_N];
    int replacements;
    int repeat;

    do {
        copyArray(arr, taskArray, size);

        replacements = replaceMultipleOfThree(taskArray, size);

        std::cout << "Array after replacement:\n";
        printArray(taskArray, size);

        std::cout << "Number of replacements: "
            << replacements << "\n\n";

        std::cout << "Run this task again? (1 - Yes, 0 - No): ";
        std::cin >> repeat;

    } while (repeat == 1);
}