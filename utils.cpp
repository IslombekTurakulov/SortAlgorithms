//
// Created by Islam on 23.02.2022.
//

#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

/**
 * Подобие tryParse как в шарпе, но работает слегка иначе
 * @example При вводе: 324523sadfas даёт 324523
 * @return результат ввода
 */
int parseInteger() {
    std::string input;
    int in;
    bool is_correct_input = true;
    std::cout << "Type here: ";
    do {
        try {
            std::cin >> input;
            in = stoi(input);
            if (in <= 0) {
                throw std::exception();
            }
        } catch (std::exception ex) {
            std::cout << "Incorrect input!" << std::endl;
            std::cout << "Type here: ";
            continue;
        }
        is_correct_input = false;
    } while (is_correct_input);
    std::cout << "Please wait..." << std::endl;
    return in;
}

/**
 * Метод для генерации чисел от 0 до N
 *
 * @param arr массив
 * @param end ограничение на генерацию
 * @param length размер
 */
void generateArr(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % end;
    }
}

/**
 * Метод для генерации чисел от 1 до N
 *
 * @param arr массив
 * @param end ограничение по генерации
 * @param length размер массива
 */
void generateReversedArr(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = 1 + (rand() % end);
    }
}

/**
 * Метод, который случайным образов переставляет индексы в массиве.
 * Тем самым даёт почти отсортированный массив чисел.
 *
 * @param arr массив
 * @param length размер
 */
void swapRandomElements(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        int index = rand() % length;
        std::swap(arr[i], arr[index]);
    }
}

/**
 * Выбор режима заполнения массива
 *
 * @param arr массив
 * @param index цифра для выбора режима
 * @param length размерность массива
 */
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
        radixSort(arr, length);
        for (int i = 0; i < length / 2; ++i) {
            std::swap(arr[i], arr[length - i - 1]);
        }
    }
}

/**
 * Метод, который подсказывает который сейчас режим был выбран.
 *
 * @param choice выбор
 * @return строка с выбранным режимом
 */
std::string choiceModeArray(int choice) {
    std::string result;
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