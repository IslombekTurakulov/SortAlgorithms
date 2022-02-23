//
// Created by Islam on 23.02.2022.
//

#include <chrono>
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::swap;
using std::vector;
using std::pair;
using std::ios_base;
using std::ios;
using std::fstream;

void writeToFile(int choice_sort,
                 vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
                 fstream *fout) {
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

void writeSortNames(int choice_sort, const vector<pair<pair<string, int>, pair<string, int64_t>>> &first_loop,
                    fstream *fout) {
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