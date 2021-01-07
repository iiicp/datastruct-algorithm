/***********************************
* File:     main.cpp
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#include <iostream>
#include "SortTest.h"
#include "insertSort.h"
#include "SelectSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

int main() {

    int n = 1e6;
    int *arr = SortTest::generalRandomArray(n, 0, n);
    int *arr2 = SortTest::copyArray(arr, n);

    //SortTest::testSort("insert sort2", insertSort2, arr, n);
    //SortTest::testSort("select sort", selectSort, arr2, n);
    SortTest::testSort("quick sort", quickSort, arr, n);
    SortTest::testSort("merge sort", mergeSort, arr2, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}