//
// Created by Islam on 16.02.2022.
//

#include "InsertionSort.h"
#include <algorithm>
#include <utility>

InsertionSort::InsertionSort(int *arr, int length) {
    this->array = arr;
    this->length = length;
}

void InsertionSort::defaultSortArray() {
    for (int first_index = 1; first_index < length; ++first_index) {
        for (int j = first_index; j > 0 && array[j - 1] > array[j]; --j) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

void InsertionSort::binarySortArray() {
    for (int first_index = 1; first_index < length; ++first_index) {
        if (array[first_index - 1] > array[first_index]) {
            int left = 0;
            int right = first_index - 1;
            int temp = array[first_index];
            left = methodSearch(left, right, temp);
            for (int index = first_index - 1; index >= left; --index) {
                array[index + 1] = array[index];
            }
            array[left] = temp;
        }
    }
}

int InsertionSort::methodSearch(int left, int right, int temp) {
    do {
        int middle = (left + right) / 2;
        array[middle] <= temp ? (left = middle + 1) : (right = middle - 1);
    } while (left <= right);
    return left;
}

InsertionSort::~InsertionSort() {
    delete[] array;
}
