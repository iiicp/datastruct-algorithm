/**********************************
 * File:     iset.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_ISET_H
#define BST_ISET_H

template <typename Key, typename Value>
class iset {
public:
  virtual void insert(Key key) = 0;
  virtual void erase(Key key) = 0;
  virtual bool contain(Key key) = 0;
  virtual int size() = 0;
  virtual bool isEmpty() = 0;
};

#endif // BST_ISET_H
