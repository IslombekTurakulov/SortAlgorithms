//
// Created by Islam on 16.02.2022.
//

#include <algorithm>
#include <vector>

/**
 * Метод для нахождения максимального элемента в массиве.
 *
 * @param n  размерность массива
 * @param arr массив
 * @return максимальный элемент в массиве
 */
int getMax(int n, int *arr) {
    int res = arr[0];
    for (int i = 1; i < n; ++i) {
        res = std::max(res, arr[i]);
    }
    return res;
}

/**
 * Сортировка подсчётом
 *
 * @param arr массив
 * @param length размерность массива
 */
void countingSortArray(int *arr, int length) {
    auto max_length = getMax(length, arr);
    int *second = new int[max_length + 1];
    for (int i = 0; i < max_length + 1; ++i) {
        second[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        ++second[arr[i]];
    }
    int index = 0;
    for (int index_iter = 0; index_iter < max_length + 1; ++index_iter) {
        for (int iteration = 0; iteration < second[index_iter]; ++iteration) {
            arr[index] = index_iter;
            ++index;
        }
    }
    delete[] second;
}

/**
 * Цифровая сортировка
 *
 * @param array массив
 * @param length размерность массива
 */
void radixSort(int *array, int length) {
    int exp = 1;
    std::vector<int> second(length * 4);
    int max = getMax(length, array);
    for (; max / exp > 0;) {
        std::vector<int> box(256, 0);
        int iteration;
        for (iteration = 0; iteration < length; ++iteration) {
            ++box[array[iteration] / exp % 256];
        }
        for (iteration = 1; iteration < 256; ++iteration) {
            box[iteration] += box[iteration - 1];
        }
        for (iteration = length - 1; iteration >= 0; --iteration) {
            second[--box[array[iteration] / exp % 256]] = array[iteration];
        }
        for (iteration = 0; iteration < length; ++iteration) {
            array[iteration] = second[iteration];
        }
        exp *= 256;
    }
}
