//
// Created by Islam on 23.02.2022.
//

#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

/**
 * Метод, который сортирует массив
 *
 * @param array массив
 * @param choice_sort выбор режима сортировки
 * @param length размерность
 * @return строка с выбранной сортировкой
 */
std::string takeTheSort(int *array, int choice_sort, int length) {
    std::string nameOfSort;
    if (choice_sort == 1) {
        selectionSort(array, length);
        nameOfSort = "Selection Sort";
    } else if (choice_sort == 2) {
        bubbleSort(array, length);
        nameOfSort = "Bubble Sort";
    } else if (choice_sort == 3) {
        bubbleSortIversonFirst(array, length);
        nameOfSort = "Bubble Iverson 1";
    } else if (choice_sort == 4) {
        bubbleSortIversonSecond(array, length);
        nameOfSort = "Bubble Iverson 2";
    } else if (choice_sort == 5) {
        defaultSortArray(array, length);
        nameOfSort = "Insertion Sort";
    } else if (choice_sort == 6) {
        binarySortArray(array, length);
        nameOfSort = "Binary Insertion Sort";
    } else if (choice_sort == 7) {
        countingSortArray(array, length);
        nameOfSort = "Counting Sort";
    } else if (choice_sort == 8) {
        radixSort(array, length);
        nameOfSort = "Radix Sort";
    } else if (choice_sort == 9) {
        mergePivot(array, 0, length - 1);
        nameOfSort = "Merge Sort";
    } else if (choice_sort == 10) {
        hoareQuickSort(array, 0, length - 1);
        nameOfSort = "QuickSort Hoare partition";
    } else if (choice_sort == 11) {
        lomutoQuickSort(array, 0, length - 1);
        nameOfSort = "QuickSort Lomuto partition";
    } else if (choice_sort == 12) {
        startHeapSort(array, length);
        nameOfSort = "HeapSort";
    }
    return nameOfSort;
}

/**
 * Метод, который позволяет узнать, отсортирован ли массив или нет
 *
 * @param arr массив
 * @param n размерность
 * @return  1 или 0 аналог True/False
 */
int arraySortedOrNot(int *arr, int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    if (arr[n - 1] < arr[n - 2]) {
        return 0;
    }
    return arraySortedOrNot(arr, n - 1);
}