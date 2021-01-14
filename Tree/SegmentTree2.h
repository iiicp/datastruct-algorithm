/**********************************
 * File:     SegmentTree2.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/14
 ***********************************/

#ifndef TREE_SEGMENTTREE2_H
#define TREE_SEGMENTTREE2_H

#include <vector>
#include <climits>

using namespace std;
template <typename E>
class SegmentTree2 {
private:
  vector<E> data;
  vector<E> tree; /// 树状数组
  E (*merge) (E, E);
public:
  SegmentTree2(vector<E> &inData, E(*mergeOps)(E a, E b)) {
    assert(inData.size() > 0);
    assert(mergeOps);

    data = vector<E>(inData);
    /// 采用满二叉树的方式来存储，最多的结点数为4n，使用INT_MIN表示null结点
    tree = vector<E>(data.size() * 4, INT_MIN);

    this->merge = mergeOps;

    /// buildSegmentTree
    buildSegmentTree(0, 0, data.size() - 1);
  }

  E query(int l, int r) {
    return query(0, 0, data.size() - 1, l, r);
  }

  void update(int index, E val) {
    assert(index>=0 && index < data.size());

    /// 先更新数据区
    data[index] = val;

    /// 更新线段树
    update(0, 0, data.size() - 1, index, val);
  }

  void printTree() {
    for (int i = 0; i < tree.size(); ++i)
      std::cout << tree[i] << " ";
    std::cout << std::endl;
  }

private:
  void buildSegmentTree(int treeIndex, int l, int r) {
    if (l == r) {
      tree[treeIndex] = data[l]; // or data[r]
      return;
    }

    int leftIndex = leftChild(treeIndex);
    int rightIndex = rightChild(treeIndex);

    int mid = l + (r - l) / 2;
    buildSegmentTree(leftIndex, l, mid);
    buildSegmentTree(rightIndex, mid + 1, r);

    /// 后序遍历的过程，当前结点的值
    tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
  }

  E query(int treeIndex, int tl, int tr, int l, int r) {
    if (tl == l && tr == r)
      return tree[treeIndex];

    int leftIndex = leftChild(treeIndex);
    int rightIndex = rightChild(treeIndex);

    int mid = tl + (tr - tl) / 2;

    if (l >= mid + 1) {
      return query(rightIndex, mid+1, tr, l, r);
    }else if (r <= mid) {
      return query(leftIndex, tl, mid, l, r);
    }

    int a = query(leftIndex, tl, mid, l, mid);
    int b = query(rightIndex, mid+1, tr, mid+1, r);
    return merge(a, b);
  }

  void update(int treeIndex, int tl, int tr, int index, E val) {
    if (tl == tr) {
      tree[treeIndex] = val;
      return;
    }

    int leftIndex = leftChild(treeIndex);
    int rightIndex = rightChild(treeIndex);

    int mid = tl + (tr - tl) / 2;

    if (index <= mid) {
      update(leftIndex, tl, mid, index, val);
    }else {
      update(rightIndex, mid+1, tr, index, val);
    }

    tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
  }

  int leftChild(int index) {
    return index * 2 + 1;
  }

  int rightChild(int index) {
    return index * 2 + 2;
  }
};

#endif // TREE_SEGMENTTREE2_H
