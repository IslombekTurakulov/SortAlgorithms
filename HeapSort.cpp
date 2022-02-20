//
// Created by Islam on 20.02.2022.
//

#include <algorithm>

void heapSort(int *heap_arr, int length, int index) {
    int max_index = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < length && heap_arr[left] > heap_arr[max_index]) {
        max_index = left;
    }
    if (right < length && heap_arr[right] > heap_arr[max_index]) {
        max_index = right;
    }
    if (max_index != index) {
        std::swap(heap_arr[index], heap_arr[max_index]);
        heapSort(heap_arr, length, max_index);
    }
}

void startHeapSort(int *arr, int length) {
    int index = length / 2 - 1;
    while (index >= 0) {
        heapSort(arr, length, index);
        --index;
    }
    index = length - 1;
    while (index >= 0) {
        std::swap(arr[0], arr[index]);
        heapSort(arr, index, 0);
        --index;
    }
}