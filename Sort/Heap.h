/**********************************
 * File:     Heap.cpp
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/8
 ***********************************/

namespace Sort {
  template<typename Item>
  class MaxHeap {
    Item *data;
    int capacity;
    int count;

    void shiftUp(int k) {
      while (k > 1 && data[k/2] < data[k]) {
        std::swap(data[k / 2], data[k]);
        k = k/2;
      }
    }

    void shiftDown(int k) {
      while (2 * k <= count) {
        int j = 2 * k;
        if (j + 1 <= count && data[j+1] > data[j])
          j = j + 1;

        /// 交换的前提
        /// 父孩子结点必须要小于左右子孩子结点的最大值
        if (data[k] >= data[j])
          break;

        std::swap(data[k], data[j]);
        k = j;
      }
    }
  public:
    MaxHeap(int n) {
      data = new Item[n+1];
      capacity = n;
      count = 0;
    }

    MaxHeap(Item *arr, int n) {
      data = new Item[n+1];
      capacity = n;
      for (int i = 1; i < n; ++i)
        data[i] = arr[i-1];
      count = n;

      /// 从最后一个非叶子结点开始
      /// heapify 过程 !!!!
      for (int i = count/2; i >= 1; --i)
        shiftDown(i);
    }

    void insertItem(Item item) {
      if (count < capacity) {
        data[count + 1] = item;
        count += 1;

        shiftUp(count);
      }
    }

    Item extractItem() {
      Item item = data[1];
      std::swap(data[1], data[count]);
      count--;
      shiftDown(1);
      return item;
    }

    void printHeap() {
      for (int i = 1; i <= count; ++i)
        std::cout << data[i] << ", ";
      std::cout << std::endl;
    }

    int size() {
      return count;
    }

    bool isEmpty() {
      return count == 0;
    }
  };

  void heapSort(int *arr, int n) {
    MaxHeap<int> heap(arr, n);
    for (int i = 0; i < n; ++i)
      arr[i] = heap.extractItem();
  }
}