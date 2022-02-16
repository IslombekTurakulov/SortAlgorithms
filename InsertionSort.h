//
// Created by Islam on 16.02.2022.
//

#ifndef __insertionsort__
#define __insertionsort__


class InsertionSort {
    int *array;
    int length;

    int methodSearch(int left, int right, int temp);

public:
    InsertionSort(int *arr, int length);

    ~InsertionSort();

    void defaultSortArray();

    void binarySortArray();
};


#endif //__insertionsort__
