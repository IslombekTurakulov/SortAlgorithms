/*
 *  ПиАА, Туракулов Исломбек Улугбекович, БПИ204
 *  ФИО: Туракулов Исломбек Улугбекович
 *  ГРУППА: БПИ204
 *  Среда разработки: CLion, 2021.3.3 (213.6777.58)
 *  Сделано всё: графики, таблица, проверка , красивый вывод, возможность выбрать сортировки,
 *  отчёт находится в README.md или PDF вариант в папке ./Отчёт/.
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
using std::chrono::steady_clock;

void sortInformation();

pair<string, int64_t> sortAndCountTime(int choice_sort, int length, int *array);

int calcAndWriteFirst(int choice_sort,
                      vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop, int mode,
                      int *first_arr, int size);

int calcAndWriteSecond(int choice_sort,
                       vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop,
                       int mode, int *second_arr, int size);

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
    // На это измерение не обращайте внимание
    auto begin = steady_clock::now();
    // список из данных вида: {{режим заполнения, размер массива}, {название сортировки, время
    // выполнения}}
    vector<pair<pair<string, int>, pair<string, int64_t>>> first_loop;
    vector<pair<pair<string, int>, pair<string, int64_t>>> second_loop;
    int percentage = 0;
    for (int mode = 1; mode <= 4; ++mode) {
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
            // Данный метод выбирает какой режим использовать
            // Например: заполнить массив числами от 0 до 5
            chooseArray(first_arr, mode, size);
            // Вызов метода, который выполняет запись (не-)отсортированных элементов
            size = calcAndWriteFirst(choice_sort, first_loop, mode, first_arr, size);
            delete[] first_arr;
            first_arr = nullptr;
        }
        int start_second = 100;
        int end_second = 4100;
        int shift_second = 100;
        int *second_arr = new int[start_second];
        for (int size = start_second; size <= end_second; size += shift_second) {
            // Аналогично выше такой же алгоритм.
            if (start_second != size) {
                second_arr = new int[size];
            }
            chooseArray(second_arr, mode, size);
            size = calcAndWriteSecond(choice_sort, second_loop, mode, second_arr, size);
            delete[] second_arr;
            second_arr = nullptr;
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
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<std::chrono::seconds>(end - begin);
    cout << "Overall time: " << elapsed_ms.count() << " seconds"
         << "\n";
    return 0;
}

/**
 * Метод для записи данных в файл
 *
 * @param choice_sort выбранная сортировка
 * @param second_loop список из данных вида: {{режим заполнения, размер массива}, {название
 * сортировки, время выполнения}}
 */
void writeCsvToSecondFile(int choice_sort,
                          vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop) {
    fstream fout_second;
    // Открываем поток для записи данных в файл .csv
    fout_second.open("Second.csv", ios::out | ios::app);
    writeSortNames(choice_sort, second_loop, &fout_second);
    writeToFile(choice_sort, second_loop, &fout_second);
    fout_second.close();
}

/**
 * Метод для записи данных в файл
 *
 * @param choice_sort выбранная сортировка
 * @param second_loop список данных вида: {{режим заполнения, размер массива}, {название сортировки,
 * время выполнения}}
 */
void writeCsvToFirstFile(int choice_sort,
                         vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop) {
    fstream fout;
    // Открываем поток для записи данных в файл .csv
    fout.open("First.csv", ios::out | ios::app);
    writeSortNames(choice_sort, first_loop, &fout);
    writeToFile(choice_sort, first_loop, &fout);
    fout.close();
}

/**
 * Метод для сортировки и записи проверок в файл
 *
 * @param choice_sort выбранная сортировка
 * @param second_loop список данных вида: {{режим заполнения, размер массива}, {название сортировки,
 * время выполнения}}
 * @param mode режим сортировки
 * @param second_arr массив
 * @param size размерность
 * @return размер массива
 */
int calcAndWriteSecond(int choice_sort,
                       vector<pair<pair<string, int>, pair<string, int64_t>>> &second_loop,
                       int mode, int *second_arr, int size) {
    // Проверка на желаемую сортировку.
    if (choice_sort <= 0 || choice_sort >= 13) {
        // Здесь происходит замера всех видов сортировки
        for (int sort_iteration = 0; sort_iteration < 12; ++sort_iteration) {
            // Массив для дальнейшей сортировки.
            int *copied_arr = new int[size];
            // Копируем элементы с прошлого массива на новый.
            std::copy(second_arr, second_arr + size, copied_arr);
            fstream fout;
            // Открываем поток и записываем первоначальный результат массива.
            fout.open("input - 2.txt", ios::out | ios::app);
            fout << "Before"
                 << "\n";
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "After"
                 << "\n\n";
            // Происходит сортировка массива и вывод через pair<T, T> результат времени.
            auto result = sortAndCountTime(sort_iteration + 1, size, copied_arr);
            // Записывается в некий список в котором лежат следующие данные:
            // [0] -> {{режим заполнения, размер массива}, {название сортировки, время выполнения}}
            second_loop.push_back({make_pair(choiceModeArray(mode), size), result});
            // Происходит запись отсортированного результата.
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No") << "\n\n";
            fout.close();
            delete[] copied_arr;
        }
    } else {
        // Открываем поток и записываем первоначальный результат массива.
        fstream fout;
        fout.open("input - 2.txt", ios::out | ios::app);
        fout << "Before"
             << "\n";
        for (int k = 0; k < size; ++k) {
            fout << second_arr[k] << " ";
        }
        fout << "\n"
             << "After"
             << "\n\n";
        // Происходит сортировка массива и вывод через pair<T, T> результат времени.
        auto result = sortAndCountTime(choice_sort, size, second_arr);
        // Записывается в некий список в котором лежат следующие данные:
        // [0] -> {{режим заполнения, размер массива}, {название сортировки, время выполнения}}
        second_loop.push_back({make_pair(choiceModeArray(mode), size), result});
        // Происходит запись отсортированного результата.
        for (int k = 0; k < size; ++k) {
            fout << second_arr[k] << " ";
        }
        fout << "\n"
             << "Is sorted: " << (arraySortedOrNot(second_arr, size) ? "Yes" : "No") << std::endl
             << std::endl;
        fout.close();
    }
    return size;
}

/**
 * Метод для сортировки и записи проверок в файл
 *
 * @param choice_sort выбранная сортировка
 * @param second_loop список данных вида: {{режим заполнения, размер массива}, {название сортировки,
 * время выполнения}}
 * @param mode режим сортировки
 * @param second_arr массив
 * @param size размерность
 * @return размер массива
 */
int calcAndWriteFirst(int choice_sort,
                      vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop, int mode,
                      int *first_arr, int size) {
    // Проверка на желаемую сортировку.
    if (choice_sort >= 13) {
        // Здесь происходит замера всех видов сортировки
        for (int sort_iteration = 0; sort_iteration < 12; ++sort_iteration) {
            // Массив для дальнейшей сортировки.
            int *copied_arr = new int[size];
            // Копируем элементы с прошлого массива на новый.
            std::copy(first_arr, first_arr + size, copied_arr);
            // Открываем поток и записываем первоначальный результат массива.
            fstream fout;
            fout.open("input - 1.txt", ios::out | ios::app);
            fout << "Before"
                 << "\n";
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "After"
                 << "\n\n";
            // Происходит сортировка массива и вывод через pair<T, T> результат времени.
            auto result = sortAndCountTime(sort_iteration + 1, size, copied_arr);
            // Записывается в некий список в котором лежат следующие данные:
            // [0] -> {{режим заполнения, размер массива}, {название сортировки, время выполнения}}
            first_loop.push_back({make_pair(choiceModeArray(mode), size), result});
            // Происходит запись отсортированного результата.
            for (int k = 0; k < size; ++k) {
                fout << copied_arr[k] << " ";
            }
            fout << "\n"
                 << "Is sorted: " << (arraySortedOrNot(copied_arr, size) ? "Yes" : "No") << "\n\n";
            fout.close();
            delete[] copied_arr;
        }
    } else {
        // Открываем поток и записываем первоначальный результат массива.
        fstream fout;
        fout.open("input - 1.txt", ios::out | ios::app);
        fout << "Before"
             << "\n";
        for (int k = 0; k < size; ++k) {
            fout << first_arr[k] << " ";
        }
        fout << "\n"
             << "After"
             << "\n\n";
        // Происходит сортировка массива и вывод через pair<T, T> результат времени.
        auto result = sortAndCountTime(choice_sort, size, first_arr);
        // Записывается в некий список в котором лежат следующие данные:
        // [0] -> {{режим заполнения, размер массива}, {название сортировки, время выполнения}}
        first_loop.push_back({make_pair(choiceModeArray(mode), size), result});
        // Происходит запись отсортированного результата.
        for (int k = 0; k < size; ++k) {
            fout << first_arr[k] << " ";
        }
        fout << "\n"
             << "Is sorted: " << (arraySortedOrNot(first_arr, size) ? "Yes" : "No") << "\n\n";
    }
    return size;
}

/**
 * Метод, который измеряет выполнение времени сортировки массива.
 *
 * @param choice_sort выбранная сортировка
 * @param length размерность массива
 * @param array массив
 * @return название сортировки и время выполнения
 */
pair<string, int64_t> sortAndCountTime(int choice_sort, int length, int *array) {
    // Измерение времени выполнения сортировки.
    auto begin = steady_clock::now();
    // Метод takeTheSort от названия понятно, что он выбирает сортировку
    // и возвращает название сортировки, которую он использовал
    string name_of_sort = takeTheSort(array, choice_sort, length);
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<microseconds>(end - begin);
    // На выход подаётся значение вида: {название сортировки, время выполнения}
    return make_pair(name_of_sort, elapsed_ms.count());
}

/**
 * Метод для вывода информации о доступных на выбор сортировок
 */
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
