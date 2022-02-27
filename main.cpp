/*
 *  ПиАА, Туракулов Исломбек Улугбекович, БПИ204
 *  ФИО: Туракулов Исломбек Улугбекович
 *  ГРУППА: БПИ204
 *  Среда разработки: CLion, 2021.3.3 (213.6777.58)
 *  Сделано: графики, таблица, проверка , красивый вывод, возможность выбрать сортировки.
 *  Не сделано: Отсутствует.
 * */

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "Sort-Algorithms/InsertionSort.cpp"
#include "Sort-Algorithms/CountingSort.cpp"
#include "Sort-Algorithms/SelectionSort.cpp"
#include "Sort-Algorithms/BubbleSort.cpp"
#include "Sort-Algorithms/QuickSort.cpp"
#include "Sort-Algorithms/MergeSort.cpp"
#include "Sort-Algorithms/HeapSort.cpp"
#include "./utils.cpp"
#include "./csvProvider.cpp"
#include "./sortUtils.cpp"

using std::cin;
using std::cout;
using std::exception;
using std::fstream;
using std::ifstream;
using std::ios;
using std::ios_base;
using std::make_pair;
using std::ofstream;
using std::pair;
using std::string;
using std::swap;
using std::vector;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::microseconds;
using std::chrono::milliseconds;
using std::chrono::seconds;

void sortInformation();

pair<string, int64_t> sortAndCountTime(int choice_sort, int start_first, int *first_arr);

int calcAndWriteFirst(int choice_sort,
                      vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop, int i,
                      int *first_arr, int size);

int calcAndWriteSecond(int choice_sort,
                       vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop, int i,
                       int *second_arr, int size);

void writeCsvToFirstFile(int choice_sort,
                         vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop);

void writeCsvToSecondFile(int choice_sort,
                          vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop);

int main() {
    std::ios_base::sync_with_stdio(false);
    // Отображение доступных сортировок
    sortInformation();
    // Ввод цифры
    int choice_sort = parseInteger();
    vector<pair<pair<string, int>, pair<string, int64_t>>> first_loop;
    vector<pair<pair<string, int>, pair<string, int64_t>>> second_loop;
    int percentage = 0;
    for (int i = 1; i <= 4; ++i) {
        // Идём по итерации первого массива от 50 до 100
        int start_first = 50;
        int end_first = 300;
        int shift_first = 10;
        int *first_arr = new int[start_first];
        for (int size = start_first; size <= end_first; size += shift_first) {
            // Присваиваем новое size для first_arr
            if (start_first != size) {
                first_arr = new int[size];
            }
            //
            chooseArray(first_arr, i, size);
            size = calcAndWriteFirst(choice_sort, first_loop, i, first_arr, size);
        }
        int start_second = 100;
        int end_second = 4100;
        int shift_second = 100;
        int *second_arr = new int[start_second];
        for (int size = start_second; size <= end_second; size += shift_second) {
            if (start_second != size) {
                second_arr = new int[size];
            }
            chooseArray(second_arr, i, size);
            size = calcAndWriteSecond(choice_sort, second_loop, i, second_arr, size);
        }
        percentage += 20;
        cout << "Progress: " << percentage << "%"
             << "\n";
    }
    writeCsvToFirstFile(choice_sort, first_loop);
    writeCsvToSecondFile(choice_sort, second_loop);
    percentage += 20;
    cout << "Progress: " << percentage << "%" << std::endl;
    cout << "Done! Files are located to the cmake-build-debug directory" << std::endl;
    return 0;
}

void writeCsvToSecondFile(int choice_sort,
                          vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop) {
    fstream fout_second;
    fout_second.open("Second.csv", ios::out | ios::app);
    writeSortNames(choice_sort, second_loop, &fout_second);
    writeToFile(choice_sort, second_loop, &fout_second);
    fout_second.close();
}

void writeCsvToFirstFile(int choice_sort,
                         vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop) {
    std::fstream fout;
    fout.open("First.csv", ios::out | ios::app);
    writeSortNames(choice_sort, first_loop, &fout);
    writeToFile(choice_sort, first_loop, &fout);
    fout.close();
}

int calcAndWriteSecond(int choice_sort,
                       vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop, int i,
                       int *second_arr, int size) {
    if (choice_sort >= 13) {
        for (int j = 0; j < 12; ++j) {
            int *copied_arr = new int[size];
            std::copy(second_arr, second_arr + size, copied_arr);
            fstream fout;
            fout.open("input - 2.txt", ios::out | ios::app);
            fout << "Before"
                 << "\n";
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "After" << std::endl
                 << std::endl;
            auto result = sortAndCountTime(j + 1, size, copied_arr);
            second_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No")
                 << std::endl
                 << std::endl;
        }
    } else {
        fstream fout;
        fout.open("input - 2.txt", ios::out | ios::app);
        fout << "Before"
             << "\n";
        for (int k = 0; k < size; ++k) {
            fout << second_arr[k] << " ";
        }
        fout << "\n"
             << "After" << std::endl
             << std::endl;
        auto result = sortAndCountTime(choice_sort, size, second_arr);
        second_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
        for (int k = 0; k < size; ++k) {
            fout << second_arr[k] << " ";
        }
        fout << "\n"
             << "Is sorted: " << (arraySortedOrNot(second_arr, size) ? "Yes" : "No") << std::endl
             << std::endl;
    }
    return size;
}

int calcAndWriteFirst(int choice_sort,
                      vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop, int i,
                      int *first_arr, int size) {
    if (choice_sort >= 13) {
        for (int j = 0; j < 12; ++j) {
            int *copied_arr = new int[size];
            std::copy(first_arr, first_arr + size, copied_arr);
            std::fstream fout;
            fout.open("input - 1.txt", ios::out | ios::app);
            fout << "Before"
                 << "\n";
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "After"
                 << "\n\n";
            auto result = sortAndCountTime(j + 1, size, copied_arr);
            first_loop.push_back({make_pair(choiceRandomArray(i), size), result});
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No") << "\n\n";
            fout.close();
        }
    } else {
        std::fstream fout;
        fout.open("input - 1.txt", ios::out | ios::app);
        fout << "Before"
             << "\n";
        for (int k = 0; k < size; ++k) {
            fout << first_arr[k] << " ";
        }
        fout << "\n"
             << "After"
             << "\n";
        auto result = sortAndCountTime(choice_sort, size, first_arr);
        first_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
        for (int k = 0; k < size; ++k) {
            fout << first_arr[k] << " ";
        }
        fout << "\n"
             << "Is sorted: " << (arraySortedOrNot(first_arr, size) ? "Yes" : "No") << "\n\n";
    }
    return size;
}

pair<string, int64_t> sortAndCountTime(int choice_sort, int start_first, int *first_arr) {
    auto begin = std::chrono::steady_clock::now();
    string name_of_sort = takeTheSort(first_arr, choice_sort, start_first);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = duration_cast<std::chrono::microseconds>(end - begin);
    return make_pair(name_of_sort, elapsed_ms.count());
}

void sortInformation() {
    cout << "===== Available sort algorithms ====="
         << "\n";
    cout << "[1] - Selection sort"
         << "\n";
    cout << "[2] - Bubble sort"
         << "\n";
    cout << "[3] - Bubble sort v 1"
         << "\n";
    cout << "[4] - Bubble sort v 1 and 2"
         << "\n";
    cout << "[5] - Insertion sort"
         << "\n";
    cout << "[6] - Binary insertion sort"
         << "\n";
    cout << "[7] - Counting sort"
         << "\n";
    cout << "[8] - Radix sort"
         << "\n";
    cout << "[9] - Merge sort"
         << "\n";
    cout << "[10] - QuickSort (Hoare partition)"
         << "\n";
    cout << "[11] - QuickSort (Lomuto partition)"
         << "\n";
    cout << "[12] - HeapSort"
         << "\n";
    cout << "[13] - Choose all sort algorithms"
         << "\n";
    cout << "By default program choose - [13]"
         << "\n";
    cout << "================================="
         << "\n";
}
