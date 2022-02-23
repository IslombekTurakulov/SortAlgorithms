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
#include <algorithm>
#include <utility>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#include "./InsertionSort.cpp"
#include "./CountingSort.cpp"
#include "./SelectionSort.cpp"
#include "./BubbleSort.cpp"
#include "./QuickSort.cpp"
#include "./MergeSort.cpp"
#include "./HeapSort.cpp"

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::vector;
using std::pair;
using std::ios_base;
using std::ios;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::make_pair;
using std::exception;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::seconds;

int parseInteger();

void sortInformation();

string takeTheSort(int *array, int choice_sort, int length);

void generateArr(int *arr, int end, int length);

void generateReversedArr(int *arr, int end, int length);

void swapRandomElements(int *arr, int length);

void chooseArray(int *arr, int index, int length);

pair<string, int64_t> sortAndCountTime(int choice_sort, int start_first, int *first_arr);

void writeToFile(int choice_sort, vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
                 fstream *fout);

void writeSortNames(int choice_sort, const vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
               fstream *fout);

string choiceRandomArray(int choice);

int arraySortedOrNot(int arr[], int n);

int main() {
    std::ios_base::sync_with_stdio(false);
    sortInformation();
    int choice_sort = parseInteger();
    vector<pair<pair<string, int>, pair<string, int64_t>>> first_loop;
    vector<pair<pair<string, int>, pair<string, int64_t>>> second_loop;
    int percentage = 0;
    for (int i = 1; i <= 4; ++i) {
        int start_first = 50;
        int end_first = 300;
        int shift_first = 10;
        int *first_arr = new int[start_first];
        for (int size = start_first; size <= end_first; size += shift_first) {
            if (start_first != size) {
                first_arr = new int[size];
            }
            chooseArray(first_arr, i, size);
            if (choice_sort >= 13) {
                for (int j = 0; j < 12; ++j) {
                    int *copied_arr = new int[size];
                    std::copy(first_arr, first_arr + size, copied_arr);
                    std::fstream fout;
                    fout.open("input - 1.txt", ios::out | ios::app);
                    fout << "Before" << "\n";
                    for (int k = 0; k < size; ++k) {
                        fout << copied_arr[k] << " ";
                    }
                    fout << "\n" << "After" << "\n\n";
                    auto result = sortAndCountTime(j + 1, size, copied_arr);
                    first_loop.push_back({make_pair(choiceRandomArray(i), size), result});
                    for (int k = 0; k < size; ++k) {
                        fout << copied_arr[k] << " ";
                    }
                    fout << "\n" << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No") << "\n\n";
                    fout.close();
                }
            } else {
                std::fstream fout;
                fout.open("input - 1.txt", ios::out | ios::app);
                fout << "Before" << "\n";
                for (int k = 0; k < size; ++k) {
                    fout << first_arr[k] << " ";
                }
                fout << "\n" << "After" << "\n";
                auto result = sortAndCountTime(choice_sort, size, first_arr);
                first_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
                for (int k = 0; k < size; ++k) {
                    fout << first_arr[k] << " ";
                }
                fout << "\n" << "Is sorted: " << (arraySortedOrNot(first_arr, size) ? "Yes" : "No") << "\n\n";
            }
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
            if (choice_sort >= 13) {
                for (int j = 0; j < 12; ++j) {
                    int *copied_arr = new int[size];
                    std::copy(second_arr, second_arr + size, copied_arr);
                    fstream fout;
                    fout.open("input - 2.txt", ios::out | ios::app);
                    fout << "Before" << "\n";
                    for (int k = 0; k < size; ++k) {
                        fout << copied_arr[k] << " ";
                    }
                    fout << "\n" << "After" << std::endl << std::endl;
                    auto result = sortAndCountTime(j + 1, size, copied_arr);
                    second_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
                    for (int k = 0; k < size; ++k) {
                        fout << copied_arr[k] << " ";
                    }
                    fout << "\n" << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No") << std::endl
                         << std::endl;
                }
            } else {
                fstream fout;
                fout.open("input - 2.txt", ios::out | ios::app);
                fout << "Before" << "\n";
                for (int k = 0; k < size; ++k) {
                    fout << second_arr[k] << " ";
                }
                fout << "\n" << "After" << std::endl << std::endl;
                auto result = sortAndCountTime(choice_sort, size, second_arr);
                second_loop.push_back({std::make_pair(choiceRandomArray(i), size), result});
                for (int k = 0; k < size; ++k) {
                    fout << second_arr[k] << " ";
                }
                fout << "\n" << "Is sorted: " << (arraySortedOrNot(second_arr, size) ? "Yes" : "No") << std::endl
                     << std::endl;
            }
        }
        percentage += 20;
        cout << "Progress: " << percentage << "%" << "\n";
    }
    // file pointer
    std::fstream fout;
    fout.open("First.csv", ios::out | ios::app);
    writeSortNames(choice_sort, first_loop, &fout);
    writeToFile(choice_sort, first_loop, &fout);
    fout.close();

    fstream fout_second;
    fout_second.open("Second.csv", ios::out | ios::app);
    writeSortNames(choice_sort, second_loop, &fout_second);
    writeToFile(choice_sort, second_loop, &fout_second);
    fout_second.close();
    percentage += 20;
    cout << "Progress: " << percentage << "%" << std::endl;
    cout << "Done! Files are located to the cmake-build-debug directory" << std::endl;
    return 0;
}

void
writeSortNames(int choice_sort, const vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
               std::fstream *fout) {
    if (choice_sort >= 13) {
        (*fout) << "Mode" << ';' << "size" << ';' << "Selection Sort" << ';' << "Bubble Sort" << ';'
                << "Bubble Sort Iverson 1" << ';' <<
                "Bubble Sort Iverson 1 and 2" << ';' << "Insertion Sort" << ';' << "Binary Insertion Sort" << ';' <<
                "Counting Sort" << ';' << "Radix Sort" << ';' << "Merge Sort" << ';' << "QuickSort Hoare partition" <<
                ';' << "QuickSort Lomuto partition" << ';' << "HeapSort" << std::endl;
    } else {
        (*fout) << "Mode" << ';' << "Size" << ';' << first_loop[0].second.first << std::endl;
    }
}

void writeToFile(int choice_sort, vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
                 std::fstream *fout) {
    bool is_size_has_written;
    for (auto &row: first_loop) {
        if (choice_sort >= 13) {
            if (!is_size_has_written) {
                (*fout) << row.first.first << ';' << row.first.second << ';' << row.second.second << ';';
                is_size_has_written = true;
            } else {
                if (row.second.first == "HeapSort") {
                    (*fout) << row.second.second << std::endl;
                    is_size_has_written = false;
                } else {
                    (*fout) << row.second.second << ';';
                }
            }
        } else {
            (*fout) << row.first.first << ';' << row.first.second << ';' << row.second.second << std::endl;
        }
    }
}

pair<string, int64_t> sortAndCountTime(int choice_sort, int start_first, int *first_arr) {
    auto begin = std::chrono::steady_clock::now();
    string name_of_sort = takeTheSort(first_arr, choice_sort, start_first);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = duration_cast<std::chrono::microseconds>(end - begin);
    return make_pair(name_of_sort, elapsed_ms.count());
}

string takeTheSort(int *array, int choice_sort, int length) {
    string nameOfSort;
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

int parseInteger() {
    string input;
    int in = 0;
    bool is_correct_input = true;
    cout << "Type here: ";
    do {
        try {
            cin >> input;
            in = stoi(input);
            if (in <= 0) {
                throw exception();
            }
        } catch (exception ex) {
            cout << "Incorrect input!" << std::endl;
            cout << "Type here: ";
            continue;
        }
        is_correct_input = false;
    } while (is_correct_input);
    cout << "Please wait..." << std::endl;
    return in;
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

string choiceRandomArray(int choice) {
    string result;
    if (choice == 1) {
        result = "From 0 to 5";
    } else if (choice == 2) {
        result = "From 0 to 4000";
    } else if (choice == 3) {
        result = "Almost Sorted";
    } else {
        result = "Reversed sorted";
    }
    return result;
}

int arraySortedOrNot(int *arr, int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    if (arr[n - 1] < arr[n - 2]) {
        return 0;
    }
    return arraySortedOrNot(arr, n - 1);
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
