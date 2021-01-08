/**********************************
 * File:     Sort.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/8
 ***********************************/

#ifndef SORTTEST_SORT_H
#define SORTTEST_SORT_H

namespace Sort {

  void insertSort(int *arr, int len);
  void insertSort2(int *arr, int len);
  void insertSort3(int *arr, int l, int r);

  void selectSort(int *arr, int n);

  void mergeSort(int *arr, int n);
  void quickSort(int *arr, int n);

  void heapSort(int *arr, int n);
}

#endif // SORTTEST_SORT_H
