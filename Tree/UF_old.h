/**********************************
 * File:     UnionFind.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/14
 ***********************************/

#ifndef TREE_UNIONFIND_OLD_H
#define TREE_UNIONFIND_OLD_H

#include <vector>
using namespace std;
class UF_OLD {
private:
  vector<int> parent;
  vector<int> rank; /// 基于rank优化，合并两颗树
public:
  UF_OLD(int size) {
    assert(size > 0);
    parent = vector<int>(size, 0);
    rank = vector<int>(size, 1);
    for (int i = 0; i < size; ++i) {
      parent[i] = i; /// 默认当前id的parent就是其自己
    }
  }

  /// 判断区域p和区域q是否连通
  bool isConnected(int p, int q) {
    return find(p) == find(q);
  }

  /// 将区域p和区域q进行连通
  void unionElement(int p, int q) {
    int p1 = find(p);
    int p2 = find(q);
    if (p1 == p2)
      return;
    if (rank[p1] < rank[p2])
      parent[p1] = p2;
    else if (rank[p1] > rank[p2])
      parent[p2] = p1;
    else {
      parent[p1] = p2;
      rank[p2]++;
    }
  }

  void print() {
    for (int i = 0; i < parent.size(); ++i)
      std::cout << parent[i] << " ";
    std::cout << std::endl;
  }

private:
  /// 查找p所对应的区域的根
  int find(int p) {
    while (parent[p] != p) {
      //parent[p] = parent[parent[p]]; /// 路径压缩
      p = parent[p];
    }
    return p;
  }
};

#endif // TREE_UNIONFIND_H
