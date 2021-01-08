/***********************************
* File:     MergeSort.h
*
* Author:   caipeng
*
* Email:    iiicp@outlook.com
*
* Date:     2021/1/7
***********************************/

#ifndef SORTTEST_MERGESORT_H
#define SORTTEST_MERGESORT_H
#include "Sort.h"

namespace Sort {

  void __merge(int *arr, int l, int mid, int r) {
#if 1
    int aux[r - l + 1];
    //int *temp = new int[r-l+1];

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
      if (arr[i] <= arr[j]) {
        aux[k++] = arr[i++];
      }
      else {
        aux[k++] = arr[j++];
      }
    }
    /// 注意此处 需要while循环去...
    while (i <= mid) {
      aux[k++] = arr[i++];
    }
    while (j <= r) {
      aux[k++] = arr[j++];
    }

    for (int i = 0; i < k; ++i) {
      arr[l + i] = aux[i];
    }
    //delete[] aux;
#else
    //* VS不支持动态长度数组, 即不能使用 T aux[r-l+1]的方式申请aux的空间
    //* 使用VS的同学, 请使用new的方式申请aux空间
    //* 使用new申请空间, 不要忘了在__merge函数的最后, delete掉申请的空间:)
    int aux[r-l+1];
    //T *aux = new T[r-l+1];

    for( int i = l ; i <= r; i ++ )
      aux[i-l] = arr[i];

    // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
    int i = l, j = mid+1;
    for( int k = l ; k <= r; k ++ ){

      if( i > mid ){  // 如果左半部分元素已经全部处理完毕
        arr[k] = aux[j-l]; j ++;
      }
      else if( j > r ){  // 如果右半部分元素已经全部处理完毕
        arr[k] = aux[i-l]; i ++;
      }
      else if( aux[i-l] < aux[j-l] ) {  // 左半部分所指元素 < 右半部分所指元素
        arr[k] = aux[i-l]; i ++;
      }
      else{  // 左半部分所指元素 >= 右半部分所指元素
        arr[k] = aux[j-l]; j ++;
      }
    }
#endif
  }

  void __mergeSort(int *arr, int l, int r) {
    if (l >= r)
      return;
//    if (r - l < 15) {
//      insertSort3(arr, l, r);
//      return;
//    }

    int mid = l + (r - l) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    /// 优化trick
    if (arr[mid] > arr[mid+1])
      __merge(arr, l, mid, r);
  }

  void mergeSort(int *arr, int n) {

    if (arr == nullptr || n <= 0)
      return;

    __mergeSort(arr, 0, n - 1);
  }
}

#endif //SORTTEST_MERGESORT_H
