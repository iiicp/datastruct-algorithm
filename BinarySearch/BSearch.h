/**********************************
 * File:     BSearch.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/18
 ***********************************/

#ifndef BS_BSEARCH_H
#define BS_BSEARCH_H

#include <cassert>

template <typename E>
class BSearch {
private:
  BSearch() {}
  ~BSearch() {}
public:

  static BSearch<E> *getSharedInstance() {
    static BSearch<E> theInstance;
    return &theInstance;
  }

  /// 找到了返回该index，找不到返回-1
  int binary_search_normal(E *arr, int len, E target) {

    assert(arr && len > 0);

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

  /// 查找大于target的最小的index
  /// 边界check: 如果target大于数组最大元素，返回数组最后一个元素的下一个index
  /// 如果target小于数组的最小元素，返回数组第一个元素
  int binary_search_upper(E *arr, int len, E target) {

     assert(arr && len > 0);

     int l = 0, r = len;
     while (l < r) {
       int mid = l + (r - l) / 2;
       if (target >= arr[mid])
         l = mid + 1;
       else
         r = mid;
     }
     return l;
  }

  /// 查找小于target的最大的index
  /// 边界check: 如果target大于数组最大元素，取数组最后一个元素的index
  /// 如果target小于数组的最小元素，则返回-1
  int binary_search_lower(E *arr, int len, E target) {

    assert(arr && len > 0);

    int l = -1, r = len - 1;
    while (l < r) {
      int mid = l + (r - l + 1) / 2; /// 注意这里进行了加1操作，让其向上取整
      if (target <= arr[mid])
        r = mid - 1;
      else
        l = mid; /// 注意此处，左边界有可能没更新
    }
    return l;
  }

  /// 查找大于等于target的index
  /// 如果找到了target，返回其最大的那个index
  /// 如果没有找到target，返回大于其值的最小的index
  int binary_search_upper_ceil(E *arr, int len, E target) {

    assert(arr && len > 0);

    int upperIndex = binary_search_upper(arr, len, target);
    if (upperIndex > 0 && arr[upperIndex - 1] == target)
      return upperIndex - 1;

    return upperIndex;
  }

  /// 查找大于等于target的index
  /// 如果找到了target，返回其最小的index
  /// 如果没有找到target，返回大于其值的最小的index
  int binary_search_lower_ceil(E *arr, int len, E target) {

    assert(arr && len > 0);

    int lowerIndex = binary_search_lower(arr, len, target);
    if (lowerIndex < len - 1 && arr[lowerIndex + 1] == target)
      return lowerIndex + 1;
    return binary_search_upper(arr, len, target);
  }

  /// 查找小于等于target的index
  /// 如果找到了target，返回其最大的index
  /// 如果没有找到target，返回小于target的最大的index
  int binary_search_upper_floor(E *arr, int len, E target) {

    assert(arr && len > 0);
    int upperIndex = binary_search_upper(arr, len, target);
    if (upperIndex > 0 && arr[upperIndex - 1] == target)
      return upperIndex - 1;
    return binary_search_lower(arr, len, target);
  }

  /// 查找小于等于target的index
  /// 如果找到了target，返回其最小的index
  /// 如果没有找到target, 返回小于target的最大的index
  int binary_search_lower_floor(E *arr, int len, E target) {

    assert(arr && len > 0);
    int lowerIndex = binary_search_lower(arr, len, target);
    if (lowerIndex < len - 1 && arr[lowerIndex + 1] == target)
      return lowerIndex + 1;
    return lowerIndex;
  }
};

#endif // BS_BSEARCH_H
