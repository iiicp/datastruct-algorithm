/**********************************
 * File:     main.cpp
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/9
 ***********************************/
#include "BinarySearchTree.h"

int main() {

  BST::BinarySearchTree<int, int> bst;
  for (int i = 0; i < 10; ++i)
    bst.insertNode(i, i);

  bst.deleteNode(5);

  bst.preOrderTravel();
  bst.inOrderTravel();
  bst.postOrderTravel();
  bst.levelOrderTravel();

  std::cout << bst.size() << std::endl;

  std::cout << bst.containNode(5) << std::endl;
  std::cout << bst.containNode(6) << std::endl;

  int *value = bst.searchNode(5);
  if (value == nullptr)
    std::cout << "not find" << std::endl;
  value = bst.searchNode(6);
  if (value)
    std::cout << "find" << std::endl;

  return 0;
}
