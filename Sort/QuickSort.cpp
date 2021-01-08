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
#include "Sort.h"
#include <time.h>

namespace Sort {

  int __partion(int *arr, int l, int r) {

    /// 随机化版本
    std::swap(arr[l], arr[rand() % (r-l+1) + l]);

    int v = arr[l];

    /// arr[l+1, j] <= v  arr[j+1, i) > v
    int j = l;
    for (int i = j + 1; i <= r; ++i) {
      if (arr[i] < v) {
        std::swap(arr[j + 1], arr[i]);
        j++;
      }
    }
    std::swap(arr[l], arr[j]);
    return j;
  }

  /// |v|  < v  |     | > v |
  int __partion2(int *arr, int l, int r) {

    std::swap(arr[l], arr[rand() % (r - l + 1) + l]);
    int aux = arr[l];

    /// arr[l+1, i) <= v
    /// arr(j, r] >= v
    /// 因为i是从左向右变化的量，j是从右向左变换的量
    int i = l+1, j = r;
    while (true) {
        while (i <= r && arr[i] < aux)
            i++;
        while (j >= l+1 && arr[j] > aux)
            j--;

        if (i >= j)
            break;

        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
    std::swap(arr[l], arr[j]);
    return j;
  }

  void __quickSort(int *arr, int l, int r) {
    if (l >= r)
      return;

    int p = __partion2(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
  }

  void quickSort(int *arr, int n) {

    if (arr == nullptr || n <= 0)
      return;

    srand((unsigned)time(NULL));

    __quickSort(arr, 0, n - 1);
  }

  void __quickSort3Ways(int *arr, int l, int r) {
      if (l >= r)
          return;

      std::swap(arr[l], arr[rand() % (r - l + 1) + l]);

      int aux = arr[l];

      /// a[l+1, lt]
      /// a[lt+1, i) == e
      /// a[gt, r]
      /// 只有当前考虑的变量用i
      int lt = l;
      int gt = r + 1;
      int i = lt+1;
      while (i < gt) {
          if (arr[i] < aux) {
              std::swap(arr[lt + 1], arr[i]);
              lt++;
              i++;
          }else if (arr[i] > aux) {
              std::swap(arr[gt - 1], arr[i]);
              gt--;
          }else {
              i++;
          }
      }

      std::swap(arr[l], arr[lt]);

      __quickSort3Ways(arr, l, lt - 1);
      __quickSort3Ways(arr, gt, r);
  }

  void quickSort3Ways(int *arr, int n) {

      if (arr == nullptr || n <= 0)
          return;
      srand((unsigned)time(NULL));

      __quickSort3Ways(arr, 0, n - 1);
  }
}

#endif //SORTTEST_QUICKSORT_H
