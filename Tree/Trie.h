/**********************************
 * File:     Trie.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/14
 ***********************************/

#ifndef TREE_TRIE_H
#define TREE_TRIE_H
#include <map>
#include <string>
using namespace std;
class Trie {
private:
  class Node {
  public:
    bool isWord;
    map<char, Node*> next;

    Node(bool isWord) {
      this->isWord = isWord;
    }

    Node() {
      isWord = false;
    }
  };
  Node *root;
  int count;
public:
  Trie() {
    root = new Node();
    count = 0;
  }

  int size() {
    return count;
  }

  void add(string word) {
    Node *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      if (cur->next.find(c) == cur->next.end()) {
        cur->next[c] = new Node();
      }
      cur = cur->next[c];
    }
    /// 防止重复添加 count
    if (cur->isWord == false) {
      cur->isWord = true;
      count++;
    }
  }

  bool contains(string word) {
    Node *cur = root;
    for (int i = 0; i < word.size(); ++i) {
      char c = word[i];
      if (cur->next.find(c) == cur->next.end())
        return false;
      cur = cur->next[c];
    }
    return cur->isWord;
  }

  bool isPrefix(string prefix) {
    Node *cur = root;
    for (int i = 0; i < prefix.size(); ++i) {
      char c = prefix[i];
      if (cur->next.find(c) == cur->next.end())
        return false;
      cur = cur->next[c];
    }
    return true;
  }
};

#endif // TREE_TRIE_H
