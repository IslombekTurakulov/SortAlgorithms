//
// Created by Islam on 16.02.2022.
//

#include "SelectionSort.h"
#include <algorithm>
#include <utility>

SelectionSort::SelectionSort(int *array, int length) {
    this->array = array;
    this->length = length;
}

void SelectionSort::sortArray() {
    for (int first_index = 0; first_index < length; ++first_index) {
        int minimum = array[first_index];
        int temp_index = first_index;
        for (int second_index = first_index; second_index < length; ++second_index) {
            if (array[second_index] < minimum) {
                minimum = array[second_index];
                temp_index = second_index;
            }
        }
        if (first_index != temp_index) {
            std::swap(array[first_index], array[temp_index]);
        }
    }
}

SelectionSort::~SelectionSort() {
    delete[] array;
}
