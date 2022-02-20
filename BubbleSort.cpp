//
// Created by Islam on 18.02.2022.
//

#include <algorithm>

void bubbleSort(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) {
        for (int j = 0; j < length - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortIversonFirst(int *arr, int length) {
    for (int i = 0; i < length - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < length - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void bubbleSortIversonSecond(int *array, int length) {
    int prev = length - 1;
    for (int i = 0; i < length - 1; i++) {
        bool swapped;
        int bound = prev;
        prev = 0;
        for (int j = 0; j < bound; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
                prev = j;
            }
        }
        if (!swapped) {
            break;
        }
    }
}