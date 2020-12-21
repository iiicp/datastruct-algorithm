/**********************************
 * File:     main.cpp.c
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2020/12/21
 ***********************************/

#include <iostream>

using namespace std;

template<typename T>
int binarySearch(T arr[], int n, T target) {
  int left = 0;
  int right = n - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }
  return -1;
}

template<typename T>
int __binarySearch2(T arr[], int l, int r, T target) {
  if (l > r)
    return -1;
  int mid = l + (r - l) / 2;
  if (arr[mid] == target)
    return mid;
  else if (arr[mid] < target)
    return __binarySearch2(arr, mid + 1, r, target);
  else
    return __binarySearch2(arr, l, mid - 1, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target) {
  return __binarySearch2(arr, 0, n - 1, target);
}

int main() {

  // 准备数据集
  int n = 1e6;
  int *a = new int [n];
  for (int i = 0; i < n; i++)
    a[i] = i;

  // clock是每秒的clock数目
  // 一倍的空间能查找到，一倍的空间查找不到
  clock_t startTime = clock();
  for (int i = 0; i < 2*n; ++i) {
    int v = binarySearch(a, n, i);
    if (i < n)
      assert( v == i );
    else
      assert( v == -1 );
  }
  clock_t endTime = clock();
  cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;


  startTime = clock();
  for (int i = 0; i < 2*n; ++i) {
    int v = binarySearch2(a, n, i);
    if (i < n)
      assert( v == i );
    else
      assert( v == -1 );
  }
  endTime = clock();
  cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

  delete[] a;

  return 0;
}
