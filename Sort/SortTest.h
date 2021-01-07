/***********************************
* File:     SortTest.h
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#ifndef SORTTEST_SORTTEST_H
#define SORTTEST_SORTTEST_H

#include <stdio.h>
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

namespace SortTest {

    int *generalRandomArray(int n, int low, int hi) {
        assert(n > 0);
        int *arr = new int[n];

        srand((unsigned)time(NULL));

        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (hi - low + 1) + low;
        }

        return arr;
    }

    int *copyArray(int *arr, int len) {
        int *arr2 = new int[len];
        for (int i = 0; i < len; ++i) {
            arr2[i] = arr[i];
        }
        return arr2;
    }

    bool isSort(int *arr, int len) {
        for (int i = 0; i < len-1; ++i)
            if (arr[i] > arr[i+1])
                return false;
        return true;
    }

    void testSort(string name, void (*func)(int *arr, int len), int *arr, int len) {
        std::cout << "test : " << name << std::endl;
        clock_t start = clock();
        func(arr, len);
        clock_t end = clock();
        assert(isSort(arr, len));
        std::cout << "times: " << (double)(end - start)/CLOCKS_PER_SEC << std::endl;
    }

    void printArr(int *arr, int len) {

        if (arr == nullptr || len <= 0)
            return;

        for (int i = 0; i < len; ++i)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

#endif //SORTTEST_SORTTEST_H
