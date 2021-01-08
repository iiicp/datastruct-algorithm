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
#include "Sort.h"
#include "Heap.h"

int main() {
    int n = 1e6;
    std::cout << "test random array n = " << n << std::endl;

    int *arr1 = SortTest::generalRandomArray(n, 0, n);
    int *arr2 = SortTest::copyArray(arr1, n);
    int *arr3 = SortTest::copyArray(arr1, n);

    //SortTest::testSort("insert sort2", insertSort2, arr, n);
    //SortTest::testSort("select sort", selectSort, arr2, n);
    SortTest::testSort("quick sort", Sort::quickSort, arr1, n);
    SortTest::testSort("merge sort", Sort::mergeSort, arr2, n);
    SortTest::testSort("heap sort", Sort::heapSort, arr3, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    std::cout << std::endl;

    std::cout << "test nearly sort array n = " << n << std::endl;
    arr1 = SortTest::generalNearlySortArray(n, 10);
    arr2 = SortTest::copyArray(arr1, n);
    arr3 = SortTest::copyArray(arr1, n);

    //SortTest::testSort("insert sort2", insertSort2, arr, n);
    //SortTest::testSort("select sort", selectSort, arr2, n);
    SortTest::testSort("quick sort", Sort::quickSort, arr1, n);
    SortTest::testSort("merge sort", Sort::mergeSort, arr2, n);
    SortTest::testSort("heap sort", Sort::heapSort, arr3, n);

    std::cout << std::endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;


    std::cout << "test contain most repeat element n = " << n << std::endl;
    arr1 = SortTest::generalRandomArray(n, 0, 10);
    arr2 = SortTest::copyArray(arr1, n);
    arr3 = SortTest::copyArray(arr1, n);

    //SortTest::testSort("insert sort2", insertSort2, arr, n);
    //SortTest::testSort("select sort", selectSort, arr2, n);
    SortTest::testSort("quick sort", Sort::quickSort, arr1, n);
    SortTest::testSort("merge sort", Sort::mergeSort, arr2, n);
    SortTest::testSort("heap sort", Sort::heapSort, arr3, n);

    std::cout << std::endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}