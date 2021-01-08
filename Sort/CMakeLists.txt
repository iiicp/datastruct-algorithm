CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

project(SortTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(SortTest main.cpp InsertSort.cpp SelectSort.cpp MergeSort.cpp QuickSort.cpp)