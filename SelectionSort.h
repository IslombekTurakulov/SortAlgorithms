//
// Created by Islam on 16.02.2022.
//

#ifndef __selectionsort__
#define __selectionsort__


class SelectionSort {
    int *array;
    int length;

public:

    ~SelectionSort();

    SelectionSort(int *array, int length);

    void sortArray();
};


#endif //__selectionsort__
