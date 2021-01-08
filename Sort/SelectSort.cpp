/***********************************
* File:     SelectSort.h
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#ifndef SORTTEST_SELECTSORT_H
#define SORTTEST_SELECTSORT_H

#include <iostream>
#include "Sort.h"

namespace Sort {

  void selectSort(int *arr, int n) {

    if (arr == nullptr || n <= 0)
      return;

    for (int i = 0; i < n - 1; ++i) {
      int minIndex = i;
      for (int j = i; j < n; ++j) {
        if (arr[j] < arr[minIndex])
          minIndex = j;
      }
      std::swap(arr[i], arr[minIndex]);
    }
  }
}

#endif //SORTTEST_SELECTSORT_H
