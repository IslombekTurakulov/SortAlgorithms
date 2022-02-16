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

    int getMax(int n) {
        int res = first_arr[0];
        for (int i = 1; i < n; ++i) {
            res = std::max(res, first_arr[i]);
        }
        return res;
    }

public:

    ~CountingSort() {
        delete[] first_arr;
        delete[] second_arr;
    }

    CountingSort(int *arr, int length) {
        this->first_arr = arr;
        this->length = length;
    }

    void sortArray() {
        auto max_length = getMax(length);
        int *second = new int[max_length + 1];
        for (int i = 0; i < max_length + 1; ++i) {
            second[i] = 0;
        }
        for (int i = 0; i < length; ++i) {
            ++second[first_arr[i]];
        }
        int index = 0;
        for (int index_iter = 0; index_iter < max_length + 1; ++index_iter) {
            for (int iteration = 0; iteration < second[index_iter]; ++iteration) {
                first_arr[index] = index_iter;
                ++index;
            }
        }
    }
};


#endif //__countingsort__
