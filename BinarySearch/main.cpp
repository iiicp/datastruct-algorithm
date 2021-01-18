/**********************************
 * File:     main.cpp
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/18
 ***********************************/
#include <iostream>
#include "BSearch.h"

using namespace std;

template <typename E>
int binary_search_normal(E *arr, int len, E target) {

  if (arr == nullptr || len <= 0)
    return -1;

  int l = 0, r = len - 1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (target == arr[mid])
      return mid;
    else if (target < arr[mid])
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;

}

/**
 * 查找大于target的最小值的index
 * 若target大于数组所有元素，则取数组最大值的下一个index
 * 若target小于数组所有元素，则取数组第一个元素
 */
template <typename E>
int binary_search_upper(E *arr, int len, E target) {

  assert(arr && len > 0);

  int l = 0, r = len;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (target >= arr[mid]) { ///以target为中心抛掉一半
      l = mid + 1;
    }else {
      r = mid;
    }
  }
  return l;
}

/// 查找大于等于target的index
/// 如果找不到target，返回大于target的最小的index
/// 如果找到target，返回最大的index
template <typename E>
int binary_search_upper_ceil(E *arr, int len, E target) {

  assert(arr && len > 0);
  int index = binary_search_upper(arr, len, target);
  if (index > 0 && arr[index - 1] == target)
    return index - 1;
  return index;
}


/**
 * 查找小于target的最大值的index
 * 如果target大于数组所有元素，则取数组最大值的那个index
 * 如果target小于数组所有元素，则取-1
 */
template <typename E>
int binary_search_lower(E *arr, int len, E target) {

  assert(arr && len > 0);

  int l = -1, r = len - 1;
  while (l < r) {
    int mid = l + (r - l + 1) / 2;
    if (mid >= 0 && target <= arr[mid])
      r = mid - 1;
    else
      l = mid;
  }
  return l;
}

/// 查找大于等于target的index
/// 如果找不到target，返回大于target的最小的index
/// 如果找到target，返回最小的index
template <typename E>
int binary_search_lower_ceil(E *arr, int len, E target) {

  assert(arr && len > 0);

  int lowIndex = binary_search_lower(arr, len, target);
  if (lowIndex < len - 1 && arr[lowIndex + 1] == target)
    return lowIndex + 1;

  return binary_search_upper(arr, len, target);
}

/// 查找小于等于target的index
/// 如果找不到target，返回小于target的最大的index
/// 如果找到target，返回等于target的最大的index
template <typename E>
int binary_search_upper_floor(E *arr, int len, E target) {

  assert(arr && len > 0);
  int upperIndex = binary_search_upper(arr, len, target);
  if (upperIndex > 0 && arr[upperIndex-1] == target)
    return upperIndex - 1;
  return binary_search_lower(arr, len, target);
}

/// 查找小于等于target的index
/// 如果找不到target，返回小于target的最大的index
/// 如果找到target，返回等于target的最小的index
template <typename E>
int binary_search_lower_floor(E *arr, int len, E target) {

  assert(arr && len > 0);
  int lowerIndex = binary_search_lower(arr, len, target);
  if (lowerIndex < len - 1 && arr[lowerIndex + 1] == target)
    return lowerIndex + 1;
  return lowerIndex;
}

int main() {

  BSearch<int> *bs = BSearch<int>::getSharedInstance();

  std::cout << "binary search normal test..." << std::endl;
  int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_normal<int>(arr, sizeof(arr) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_normal(arr, sizeof(arr) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search upper test..." << std::endl;
  int arr2[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_upper<int>(arr2, sizeof(arr2) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_upper(arr2, sizeof(arr2) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search lower test..." << std::endl;
  int arr3[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_lower<int>(arr3, sizeof(arr3) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_lower(arr3, sizeof(arr3) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search upper ceil test..." << std::endl;
  int arr4[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_upper_ceil<int>(arr4, sizeof(arr4) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_upper_ceil(arr4, sizeof(arr4) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search lower ceil test..." << std::endl;
  int arr5[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_lower_ceil<int>(arr5, sizeof(arr5) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_lower_ceil(arr5, sizeof(arr5) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search upper floor test..." << std::endl;
  int arr6[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_upper_floor<int>(arr6, sizeof(arr6) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_upper_floor(arr6, sizeof(arr6) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  std::cout << "binary search lower floor test..." << std::endl;
  int arr7[8] = {1, 1, 2, 2, 3, 3, 4, 4};
  for (int i = 0; i < 8; ++i) {
    int index = binary_search_lower_floor<int>(arr7, sizeof(arr7) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  for (int i = 0; i < 8; ++i) {
    int index = bs->binary_search_lower_floor(arr7, sizeof(arr7) / sizeof(int), i);
    std::cout << index << " ";
  }
  std::cout << std::endl;

  return 0;
}
