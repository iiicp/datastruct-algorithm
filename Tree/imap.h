/**********************************
 * File:     imap.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_IMAP_H
#define BST_IMAP_H

template <typename Key, typename Value>
class imap {
public:
  virtual void insert(Key key, Value value) = 0;
  virtual void erase(Key key) = 0;
  virtual bool contain(Key key) = 0;
  virtual Value find(Key key) = 0;
  virtual int size() = 0;
  virtual bool isEmpty() = 0;
};

#endif // BST_IMAP_H
