//
// Created by Islam on 23.02.2022.
//

#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

int parseInteger() {
    std::string input;
    int in = 0;
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
        std::swap(arr[i], arr[index]);
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

std::string choiceRandomArray(int choice) {
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