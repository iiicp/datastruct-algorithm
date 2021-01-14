/**********************************
 * File:     SegmentTree.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/13
 ***********************************/

#ifndef TREE_SEGMENTTREE_H
#define TREE_SEGMENTTREE_H

#include <vector>
#include <climits>
#include <cassert>

namespace BST {
  using std::vector;
  template <typename E>
  class SegmentTree {
  private:
    vector<E> data;
    vector<E> tree; /// 采用满二叉树来存储, 使用INT_MIN来表示null节点
    typedef E(*Merge)(E, E);
    Merge merge;
  public:
    SegmentTree(vector<E> &d, Merge merge) {
      assert(d.size() > 0);
      assert(merge != nullptr);

      this->merge = merge;

      data = vector<E>(d);
      /**
       * 1. 若节点数 n = 2^k，则最后一层刚好占满 满二叉树 最好一行，总节点数为 2n
       * 2. 若节点数 n = 2^k + 1，则需要最后二层来存储，最后一层是前面所有层的和即 2n + 2n = 4n
       */
      tree = vector<E>(data.size() * 4, INT_MIN);
      buildTree(0, 0, data.size() - 1);
    }

    ~SegmentTree() {
      merge = nullptr;
    }

    int query(int l, int r) {
      return query(0, 0, data.size() - 1, l, r);
    }

    void update(int index, E value) {
      assert(index >= 0 && index < data.size());
      data[index] = value;

      update(0, 0, data.size() - 1, index, value);
    }

    void printTree() {
      for (int i = 0; i < tree.size(); ++i)
        std::cout << tree[i] << " ";
      std::cout << std::endl;
    }

  private:
    int leftChild(int treeIndex) {
      return 2 * treeIndex + 1;
    }

    int rightChild(int treeIndex) {
      return 2 * treeIndex + 2;
    }

    /// 后序遍历的方式
    void buildTree(int treeIndex, int l, int r) {
      /// 因为叶子区间表示的范围是 l == r
      /// 即 l == r 的判断条件过滤掉了非法的treeIndex索引
      if (l == r) {
        tree[treeIndex] = data[l];
        return;
      }
      int leftIndex = leftChild(treeIndex);
      int rightIndex = rightChild(treeIndex);
      /// 区间通过mid来进行区分
      int mid = l + (r - l) / 2;
      buildTree(leftIndex, l, mid);
      buildTree(rightIndex, mid + 1, r);
      tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
    }

    int query(int treeIndex, int l, int r, int ql, int qr) {

      if (l == ql && r == qr)
        return tree[treeIndex];

      int leftIndex = leftChild(treeIndex);
      int rightIndex = rightChild(treeIndex);

      /// 左右子树的区间通过 mid 来进行区分
      int mid = l + (r - l) / 2;

      if (qr <= mid) {
        return query(leftIndex, l, mid, ql, qr);
      }else if (ql >= mid + 1) {
        return query(rightIndex, mid + 1, r, ql, qr);
      }

      int a1 = query(leftIndex, l, mid, ql, mid);
      int a2 = query(rightIndex, mid+1, r, mid+1, qr);
      return merge(a1, a2);
    }

    /// update segment tree
    void update(int treeIndex, int l, int r, int index, E value) {
      /// 这里到叶子结点一定是 index
      if (l == r) {
        tree[treeIndex] = value;
        return;
      }

      int mid = l + (r - l) / 2;
      int leftIndex = leftChild(treeIndex);
      int rightIndex = rightChild(treeIndex);
      if (index <= mid) {
        update(leftIndex, l, mid, index, value);
      }else {
        update(rightIndex, mid + 1, r, index, value);
      }
      /// tree 要进行更新
      tree[treeIndex] = merge(tree[leftIndex], tree[rightIndex]);
    }
  };
}

#endif // TREE_SEGMENTTREE_H
