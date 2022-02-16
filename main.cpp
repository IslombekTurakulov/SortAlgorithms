#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <chrono>
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::vector;
using std::ios_base;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::exception;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::high_resolution_clock;

int parseInteger();

void sortInformation();

void takeTheSort(int *array, int choice_sort, int length);

void generateArr(int *arr, int end, int length);

void generateReversedArr(int *arr, int end, int length);

void swapRandomElements(int *arr, int length);

void chooseArray(int *arr, int index, int length);

void countTime(const duration<float, std::milli> &time_left);

int main() {
    sortInformation();
    cout << "Type here: ";
    int choice_sort = parseInteger();
    for (int i = 1; i <= 4; ++i) {
        int start_first = 50;
        int end_first = 300;
        int shift_first = 10;
        /*for (int j = start_first; j < end_first; j += shift_first) {
            int *first_arr = new int[start_first];
            chooseArray(first_arr, i, start_first);
            auto start = high_resolution_clock::now();
            takeTheSort(first_arr, choice_sort, start_first);
            auto end = high_resolution_clock::now();
            duration<float, std::milli> time_left = end - start;
            countTime(time_left);
            *//*for (int k = 0; k < start_first; ++k) {
                cout << first_arr[k] << " ";
            }
            cout << "\n";*//*
        }*/
        int start_second = 100;
        int end_second = 4100;
        int shift_second = 100;
        for (int j = start_second; j < end_second; j += shift_second) {
            int *second_arr = new int[start_second];
            chooseArray(second_arr, i, start_second);
            cout << "Before" << "\n";
            for (int k = 0; k < start_second; ++k) {
                cout << second_arr[k] << " ";
            }
            cout << "\n";
            cout << "After" << "\n";
            auto start = high_resolution_clock::now();
            takeTheSort(second_arr, choice_sort, start_second);
            auto end = high_resolution_clock::now();
            duration<float, std::milli> time_left = end - start;
            // countTime(time_left);
            for (int k = 0; k < start_second; ++k) {
                cout << second_arr[k] << " ";
            }
            cout << "\n";
            delete[] second_arr;
        }
        break;
    }
/*
     // file pointer
    fstream fout;
    // opens an existing csv file or creates a new file.
    fout.open("reportcard.csv", ios::out | ios::app);
    fout << smth
    */
    return 0;
}

void countTime(const duration<float, std::milli> &time_left) {
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time_left);
    auto sec = std::chrono::duration_cast<duration<float>>(time_left);
    cout << sec.count() << " s" << " " << milliseconds.count() << " ms" << "\n";
}

void takeTheSort(int *array, int choice_sort, int length) {
    if (choice_sort == 1) {
        SelectionSort *selection_sort = new SelectionSort(array, length);
        selection_sort->sortArray();
        delete selection_sort;
    } else if (choice_sort == 2) {

    } else if (choice_sort == 3) {

    } else if (choice_sort == 4) {

    } else if (choice_sort == 5) {
        InsertionSort *insertion_sort = new InsertionSort(array, length);
        insertion_sort->defaultSortArray();
        delete insertion_sort;
    } else if (choice_sort == 6) {
        InsertionSort *binary_insertion_sort = new InsertionSort(array, length);
        binary_insertion_sort->binarySortArray();
        delete binary_insertion_sort;
    } else if (choice_sort == 7) {
        CountingSort *countingSort = new CountingSort(array, length);
        countingSort->sortArray();
        delete countingSort;
    } else if (choice_sort == 8) {

    } else if (choice_sort == 9) {

    } else if (choice_sort == 10) {

    } else if (choice_sort == 11) {

    } else if (choice_sort == 12) {

    } else {

    }
}

int parseInteger() {
    // Logical error on i/o operation
    // Функция, которая позволяет вам установить новую маску исключения для потока.
    cin.exceptions(ios_base::failbit);
    int in = 0;
    bool is_correct_input = true;
    do {
        try {
            cin >> in;
        } catch (exception ex) {
            cout << "Incorrect input!" << "\n";
            cin.clear();
            cin.ignore();
            continue;
        }
        is_correct_input = false;
    } while (is_correct_input);
    return in;
}

void sortInformation() {
    cout << "===== Available sort algorithms =====" << "\n";
    cout << "[1] - Selection sort" << "\n";
    cout << "[2] - Bubble sort" << "\n";
    cout << "[3] - Bubble sort v 1" << "\n";
    cout << "[4] - Bubble sort v 1 and 2" << "\n";
    cout << "[5] - Insertion sort" << "\n";
    cout << "[6] - Binary insertion sort" << "\n";
    cout << "[7] - Counting sort" << "\n";
    cout << "[8] - Radix sort" << "\n";
    cout << "[9] - Merge sort" << "\n";
    cout << "[10] - QuickSort (Hoare partition)" << "\n";
    cout << "[11] - QuickSort (Lomuto partition)" << "\n";
    cout << "[12] - HeapSort" << "\n";
    cout << "[13] - Choose all sort algorithms" << "\n";
    cout << "By default program choose - [13]" << "\n";
    cout << "=================================" << "\n";
}

void generateArr(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        int input = rand() % end;
        // cout << input << " ";
        arr[i] = input;
    }
    // cout << "\n";
}

void generateReversedArr(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % end + 1;
    }
}

void swapRandomElements(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        int index = rand() % length;
        swap(arr[i], arr[index]);
    }
}

void chooseArray(int *arr, int index, int length) {
    switch (index) {
        case 1:
            generateArr(arr, 5, length);
            break;
        case 2:
            generateArr(arr, 4000, length);
            break;
        case 3:
            generateArr(arr, 4000, length);
            swapRandomElements(arr, length);
        default:
            generateReversedArr(arr, 4100, length);
    }
}
