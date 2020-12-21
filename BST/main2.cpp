/**********************************
 * File:     main2.cpp.c
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2020/12/21
 ***********************************/

#include <iostream>

using namespace std;

template <typename Key, typename Value>
class BST {
private:
  struct Node {
    Key key;
    Value value;
    Node *left;
    Node *right;

    Node(Key key, Value value) {
      this->key = key;
      this->value = value;
      this->left = this->right = nullptr;
    }
  };

  // 树的根节点，链表的头部
  Node *root;
  int count;

public:
  BST(){
    root = nullptr;
    count = 0;
  }

  ~BST() {

  }

  int size() {
    return count;
  }

  bool isEmpty() {
    return count == 0;
  }
};

int main() {
    return 0;
};