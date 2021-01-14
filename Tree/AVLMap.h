/**********************************
 * File:     AVLMap.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_AVLMAP_H
#define BST_AVLMAP_H

#include "imap.h"
#include "AVLTree.h"

namespace iiicp {
  using namespace BST;
  template <typename Key, typename Value>
  class AVLMap: public imap<Key, Value> {
  private:
    AVLTree<Key, Value> *avl;
  public:
    AVLMap() {
      avl = new AVLTree<Key, Value>();
    }
    ~AVLMap() {
      delete avl;
    }

    void insert(Key key, Value value) override {
      avl->insert(key, value);
    }

    void erase(Key key) override {
      avl->erase(key);
    }

    bool contain(Key key) override {
      return avl->contain(key);
    }

    Value find(Key key) override {
      return avl->search(key);
    }

    int size() override {
      return avl->size();
    }

    bool isEmpty() override {
      return avl->isEmpty();
    }
  };
}

#endif // BST_AVLMAP_H
