cmake_minimum_required(VERSION 3.21)
project(SortAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortAlgorithms main.cpp SelectionSort.cpp SelectionSort.h InsertionSort.cpp InsertionSort.h CountingSort.cpp CountingSort.h)
