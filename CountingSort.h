//
// Created by Islam on 16.02.2022.
//

#ifndef __countingsort__
#define __countingsort__


#include <vector>

class CountingSort {
    int *first_arr;
    int *second_arr;
    int length;

    int getMax(int n);

public:

    ~CountingSort();

    CountingSort(int *arr, int length);

    void sortArray();
};


#endif //__countingsort__
