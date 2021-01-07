/***********************************
* File:     insertSort.cpp.c
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#include <iostream>

void insertSort(int *arr, int len) {

    if (arr == nullptr || len <= 0)
        return;

    for (int i = 1; i < len; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j + 1] < arr[j])
                std::swap(arr[j+1], arr[j]);
        }
    }
}

void insertSort2(int *arr, int len) {
    if (arr == nullptr || len <= 0)
        return;

    for (int i = 1; i < len; ++i) {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            if (temp < arr[j])
                arr[j+1] = arr[j];
            else {
                arr[j+1] = temp;
                break;
            }
        }
    }
}

