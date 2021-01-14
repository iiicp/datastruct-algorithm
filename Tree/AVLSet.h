/**********************************
 * File:     AVLSet.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_AVLSET_H
#define BST_AVLSET_H

#include "iset.h"
#include "AVLTree.h"

namespace iiicp {
  using namespace BST;
  template <typename Key>
  class AVLSet : public iset<Key, void*> {
  private:
    AVLTree<Key, void*> *avlTree;
  public:
    AVLSet() {
      avlTree = new AVLTree<Key, void*>();
    }
    ~AVLSet() {
      delete avlTree;
    }

    void insert(Key key) override {
      avlTree->insert(key, nullptr);
    }

    void erase(Key key) override {
      avlTree->erase(key);
    }

    bool contain(Key key) override {
      return avlTree->contain(key);
    }

    int size() override {
      return avlTree->size();
    }

    bool isEmpty() override {
      return avlTree->isEmpty();
    }
  };
}

#endif // BST_AVLSET_H
