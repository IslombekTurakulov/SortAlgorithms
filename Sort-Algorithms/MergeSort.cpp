//
// Created by Islam on 21.02.2022.
//

/**
 * Сортировка слиянием
 *
 * @param arr массив
 * @param first левая граница
 * @param second правая граница
 * @param end размерность массива
 */
void merge(int *arr, int first, int second, int end) {
    int left_size = second - first + 1;
    int right_size = end - second;
    int left_index = 0;
    int right_index = 0;
    int current;
    int *left_arr = new int[left_size];
    int *right_arr = new int[right_size];
    for (int i = 0; i < left_size; ++i) {
        left_arr[i] = arr[first + i];
    }
    for (int i = 0; i < right_size; ++i) {
        right_arr[i] = arr[second + i + 1];
    }
    current = first;
    while (left_index < left_size && right_index < right_size) {
        int left_value = left_arr[left_index];
        int right_value = right_arr[right_index];
        arr[current] = left_value < right_value ? left_value : right_value;
        ++(arr[current] == left_value ? left_index : right_index);
        ++current;
    }
    while (left_index < left_size) {
        arr[current] = left_arr[left_index];
        ++left_index;
        ++current;
    }
    while (right_index < right_size) {
        arr[current] = right_arr[right_index];
        ++current;
        ++right_index;
    }
    delete[] left_arr;
    delete[] right_arr;
}

/**
 * Рекурсия вызова сортировки и нахождения pivot
 *
 * @param arr
 * @param left
 * @param right
 */
void mergePivot(int *arr, int left, int right) {
    if (left < right) {
        int middle = (left + right) / 2;
        mergePivot(arr, left, middle);
        mergePivot(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}