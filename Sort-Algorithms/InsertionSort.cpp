//
// Created by Islam on 16.02.2022.
//

#include <algorithm>
#include <utility>

/**
 * Сортировка вставками
 *
 * @param array массив
 * @param length размерность массива
 */
void defaultSortArray(int *array, int length) {
    for (int first_index = 1; first_index < length; ++first_index) {
        for (int j = first_index; j > 0 && array[j - 1] > array[j]; --j) {
            std::swap(array[j], array[j - 1]);
        }
    }
}

int methodSearch(int left, int right, int temp, int *array) {
    do {
        int middle = (left + right) / 2;
        array[middle] <= temp ? (left = middle + 1) : (right = middle - 1);
    } while (left <= right);
    return left;
}

/**
 * Бинарная сортировка вставками
 *
 * @param array массив
 * @param length размерность массива
 */
void binarySortArray(int *array, int length) {
    for (int first_index = 1; first_index < length; ++first_index) {
        if (array[first_index - 1] > array[first_index]) {
            int left = 0;
            int right = first_index - 1;
            int temp = array[first_index];
            left = methodSearch(left, right, temp, array);
            for (int index = first_index - 1; index >= left; --index) {
                array[index + 1] = array[index];
            }
            array[left] = temp;
        }
    }
}