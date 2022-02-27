//
// Created by Islam on 21.02.2022.
//

#include <utility>
#include <algorithm>

/**
 * Нахождение pivot для левой и правой границы
 *
 * @param arr массив
 * @param low левая граница
 * @param high правая граница
 * @return левая и правая границы
 */
std::pair<int, int> hoarePartition(int *arr, int low, int high) {
    int partition = arr[(low + high) / 2];
    int right = high;
    int left = low;
    while (left <= right) {
        while (arr[left] < partition) {
            ++left;
        }
        while (arr[right] > partition) {
            --right;
        }
        if (left > right) {
            break;
        }
        std::swap(arr[left], arr[right]);
        ++left;
        --right;
    }
    return std::make_pair(left, right);
}

/**
 * Быстрая сортировка разбиение Хоара
 *
 * @param arr массив
 * @param left левая граница
 * @param right правая граница
 */
void hoareQuickSort(int *arr, int left, int right) {
    if (left < right) {
        auto pivot = hoarePartition(arr, left, right);
        if (left < pivot.second) {
            hoareQuickSort(arr, left, pivot.second);
        }
        if (pivot.first < right) {
            hoareQuickSort(arr, pivot.first, right);
        }
    }
}

/**
 * Нахождение pivot
 *
 * @param arr массив
 * @param first левая граница
 * @param last правая граница
 * @return выбранное число из массива
 */
int lomutoPartition(int *arr, int first, int last) {
    int pivot = arr[last];
    int index = first;
    for (int i = first; i < last; ++i) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[index]);
            ++index;
        }
    }
    std::swap(arr[index], arr[last]);
    return index;
}

/**
 * Быстрая сортировка разбиение Ломуто
 *
 * @param arr  массив
 * @param left левая граница
 * @param right правая граница
 */
void lomutoQuickSort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = lomutoPartition(arr, left, right);
        lomutoQuickSort(arr, left, pivot - 1);
        lomutoQuickSort(arr, pivot + 1, right);
    }
}