/***********************************
* File:     QuickSort.h
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#ifndef SORTTEST_QUICKSORT_H
#define SORTTEST_QUICKSORT_H

#include <iostream>

int __partion(int *arr, int l, int r) {
    int v = arr[l];

    /// arr[l+1, j] <= v  arr[j+1, i) > v
    int j = l;
    for (int i = j+1; i <= r; ++i) {
        if (arr[i] < v) {
            std::swap(arr[j+1], arr[i]);
            j++;
        }
    }
    std::swap(arr[l], arr[j]);
    return j;
}

void __quickSort(int *arr, int l, int r) {
    if (l >= r)
        return;

    int p = __partion(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p + 1, r);
}

void quickSort(int *arr, int n) {

    if (arr == nullptr || n <= 0)
        return;

    __quickSort(arr, 0, n - 1);
}

#endif //SORTTEST_QUICKSORT_H
