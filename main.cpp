#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <chrono>
#include "./InsertionSort.cpp"
#include "./CountingSort.cpp"
#include "./BubbleSort.cpp"
#include "./QuickSort.cpp"
#include "./MergeSort.cpp"
#include "./HeapSort.cpp"

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

void sortAndCountTime(int choice_sort, int start_first, int *first_arr);

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    sortInformation();
    cout << "Type here: ";
    int choice_sort = parseInteger();
    for (int i = 1; i <= 4; ++i) {
        int start_first = 50;
        int end_first = 300;
        int shift_first = 10;
        int *first_arr = new int[start_first];
        for (int size = start_first; size < end_first; size += shift_first) {
            if (start_first != size) {
                first_arr = new int[size];
            }
            chooseArray(first_arr, i, size);
            if (choice_sort >= 13) {

            }
            sortAndCountTime(choice_sort, size, first_arr);
            /*for (int k = 0; k < size; ++k) {
                cout << first_arr[k] << " ";
            }
            cout << "\n";*/
        }
        int start_second = 100;
        int end_second = 4100;
        int shift_second = 100;
        int *second_arr = new int[start_second];
        for (int size = start_second; size < end_second; size += shift_second) {
            if (start_second != size) {
                second_arr = new int[size];
            }
            chooseArray(second_arr, i, size);
            if (choice_sort >= 13) {

            }
            sortAndCountTime(choice_sort, size, second_arr);
           /* for (int k = 0; k < size; ++k) {
                cout << second_arr[k] << " ";
            }
            cout << "\n";*/
        }
    }
    /* // file pointer
     ofstream fout;
     // opens an existing csv file or creates a new file.
     fout.open("reportcard.csv", ios::out | ios::app);
     for (auto& row : temp_matrix) {
         for (auto col : row)
             out << col <<',';
         out << '\n';
     }*/
    return 0;
}

void sortAndCountTime(int choice_sort, int start_first, int *first_arr) {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    auto start = high_resolution_clock::now();
    takeTheSort(first_arr, choice_sort, start_first);
    auto end = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(end - start);
    duration<double, std::milli> ms_double = end - start;
    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() << "ms\n";
}

void takeTheSort(int *array, int choice_sort, int length) {
    if (choice_sort == 1) {
        selectionSort(array, length);
    } else if (choice_sort == 2) {
        bubbleSort(array, length);
    } else if (choice_sort == 3) {
        bubbleSortIversonFirst(array, length);
    } else if (choice_sort == 4) {
        bubbleSortIversonSecond(array, length);
    } else if (choice_sort == 5) {
        defaultSortArray(array, length);
    } else if (choice_sort == 6) {
        binarySortArray(array, length);
    } else if (choice_sort == 7) {
        countingSortArray(array, length);
    } else if (choice_sort == 8) {
        radixSort(array, length);
    } else if (choice_sort == 9) {
        mergePivot(array, 0, length - 1);
    } else if (choice_sort == 10) {
        hoareQuickSort(array, 0, length - 1);
    } else if (choice_sort == 11) {
        lomutoQuickSort(array, 0, length - 1);
    } else if (choice_sort == 12) {
        startHeapSort(array, length);
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
        arr[i] = rand() % end;
    }
}

void generateReversedArr(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = 1 + (rand() % end);
    }
}

void swapRandomElements(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        int index = rand() % length;
        swap(arr[i], arr[index]);
    }
}

void chooseArray(int *arr, int index, int length) {
    if (index == 1) {
        generateArr(arr, 5, length);
    } else if (index == 2) {
        generateArr(arr, 4000, length);
    } else if (index == 3) {
        generateArr(arr, 4000, length);
        swapRandomElements(arr, length);
    } else {
        generateReversedArr(arr, 4100, length);
    }
}

