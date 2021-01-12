/**********************************
 * File:     main.cpp
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/9
 ***********************************/
#include "BSTree.h"
#include "AVLTree.h"
#include "RBTree.h"
#include <vector>
#include <string>
#include <ctime>
#include "FileOperation.h"
#include "AVLMap.h"
#include "AVLSet.h"

using namespace std;

int main() {

  std::cout << "Pride and Prejudice" << std::endl;
  vector<string> words;
  if (FileOperation::readFile("../pride-and-prejudice.txt", words)) {
    std::cout << "Total words: " << words.size() << std::endl;
#if 0
    int prideCnt = 0, prejudiceCnt = 0;
    for (auto &word : words) {
      if (word == "pride")
        ++prideCnt;
      if (word == "prejudice")
        ++prejudiceCnt;
    }
    std::cout << "Frequency of PRIDE: " << prideCnt << std::endl;
    std::cout << "Frequency of PREJUDICE: " << prejudiceCnt << std::endl;
#endif
    std::cout << "-----------------Binary Search Tree----------------" << std::endl;
    clock_t start = clock();
    BST::BinarySearchTree<string, int> bst;
    for (auto &word : words)
      if (bst.contain(word)) {
        int val = bst.search(word);
        bst.insert(word, val + 1);
      }else {
        bst.insert(word, 1);
      }
    clock_t end = clock();
    for (auto &word : words)
      assert(bst.contain(word));
    std::cout << "difference words: " << bst.size() << std::endl;
    std::cout << "Frequency of PRIDE: " << bst.search("pride") << std::endl;
    std::cout << "Frequency of PREJUDICE: " << bst.search("prejudice") << std::endl;
    std::cout << "times: " << (double)(end-start)/CLOCKS_PER_SEC << "s" << std::endl;


    std::cout << "-----------------AVLTree----------------" << std::endl;
    start = clock();
    BST::AVLTree<string, int> avl;
    for (auto &word : words)
      if (avl.contain(word)) {
        int val = avl.search(word);
        avl.insert(word, val + 1);
      }else {
        avl.insert(word, 1);
      }
    end = clock();
    for (auto &word : words)
      assert(avl.contain(word));
    std::cout << "difference words: " << bst.size() << std::endl;
    std::cout << "Frequency of PRIDE: " << bst.search("pride") << std::endl;
    std::cout << "Frequency of PREJUDICE: " << bst.search("prejudice") << std::endl;
    std::cout << "times: " << (double)(end-start)/CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << "-----------------AVLMap----------------" << std::endl;

    iiicp::AVLMap<string, int> avlMap;
    start = clock();
    for (auto &word : words)
      if (avlMap.contain(word)) {
        int val = avlMap.find(word);
        avlMap.insert(word, val + 1);
      }else {
        avlMap.insert(word, 1);
      }
    end = clock();

    for (auto &word : words)
      assert(avlMap.contain(word));

    std::cout << "difference words: " << avlMap.size() << std::endl;
    std::cout << "Frequency of PRIDE: " << avlMap.find("pride") << std::endl;
    std::cout << "Frequency of PREJUDICE: " << avlMap.find("prejudice") << std::endl;
    std::cout << "times: " << (double)(end-start)/CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << "-----------------AVLSet----------------" << std::endl;
    iiicp::AVLSet<string> avlSet;
    start = clock();
    for (auto &word : words)
      avlSet.insert(word);
    end = clock();

    for (auto &word : words)
      assert(avlSet.contain(word));

    std::cout << "difference words: " << avlSet.size() << std::endl;
    std::cout << "times: " << (double)(end-start)/CLOCKS_PER_SEC << "ms" << std::endl;

    std::cout << "-----------------RBTree----------------" << std::endl;
    start = clock();
    BST::RBTree<string, int> rbt;
    for (auto &word : words)
      if (rbt.contain(word)) {
        int val = rbt.search(word);
        rbt.insert(word, val + 1);
      }else {
        rbt.insert(word, 1);
      }
    end = clock();
    for (auto &word : words) {
      assert(rbt.contain(word));
    }
    std::cout << "difference words: " << bst.size() << std::endl;
    std::cout << "Frequency of PRIDE: " << bst.search("pride") << std::endl;
    std::cout << "Frequency of PREJUDICE: " << bst.search("prejudice") << std::endl;
    std::cout << "times: " << (double)(end-start)/CLOCKS_PER_SEC << "ms" << std::endl;
  }

  return 0;
}
