/**********************************
 * File:     Heap.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/14
 ***********************************/

#ifndef TREE_HEAP_H
#define TREE_HEAP_H
#include <vector>
using namespace std;
template <typename E>

/**
 *  最大堆实现，采用数组前面空一个元素的方案
 *  左右孩子与根的关系为
 *  i -> 2 * i
 *  i -> 2 * i + 1
 *  i/2 -> parent
 */
class Heap{
private:
  vector<E> data;
  /// 数组末尾索引
  int size;
  int capacity;
public:

  Heap(int cap) {
    data = vector<E>(cap + 1, 0);
    size = 0;
    this->capacity = cap;
  }

  Heap(vector<E> &inData) {
    size = inData.size();
    capacity = size;

    data = vector<E>(inData.size() + 1, 0);
    for (int i = 0; i < inData.size(); ++i)
      data[i + 1] = inData[i];

    /// heapify
    for (int i = size/2; i >= 1; --i) {
      shiftDown(i);
    }
  }

  void add(E element) {
    assert(size < capacity);
    data[size + 1] = element;
    size++;
    shiftUp(size);
  }

  E extractElement() {
    assert(size > 0);
    E ret = data[1];

    swap(data[1], data[size]);
    size--;

    shiftDown(1);

    return ret;
  }

private:
  void shiftDown(int k) {
    while (2 * k <= size) {
      int f = 2 * k;
      if (f+1 <= size && data[f] < data[f+1])
        f = f + 1;
      /// 如果当前孩子小于左右孩子的最大值就进行交换
      if (data[k] >= data[f])
        break;
      swap(data[k], data[f]);
      k = f;
    }
  }

  void shiftUp(int k) {
    while (k > 1 && data[k/2] < data[k]) {
      swap(data[k/2], data[k]);
      k = k/2;
    }
  }
};

#endif // TREE_HEAP_H
