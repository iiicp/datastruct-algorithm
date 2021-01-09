/**********************************
 * File:     BinarySearchTree.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/9
 ***********************************/

#ifndef SORTTEST_BINARYSEARCHTREE_H
#define SORTTEST_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>

using namespace std;

namespace BST {
  template <typename Key, typename Value>
  class BinarySearchTree {
  private:
      class Node {
      public:
        Key key;
        Value value;
        Node * left;
        Node * right;

        Node(Key key, Value value) {
          this->key = key;
          this->value = value;
          this->left = nullptr;
          this->right = nullptr;
        }

        Node(Node *node) {
          this->key = node->key;
          this->value = node->value;
          this->left = node->left;
          this->right = node->right;
        }
      };

      Node *root;
      int count;

    public:
      BinarySearchTree() {
        root = nullptr;
        count = 0;
      }

      ~BinarySearchTree() {
        destroy(root);
      }

      /// 外层的接口不用管返回值
      void insertNode(Key key, Value value) {
        root = insertNode(root, key, value);
      }

      void deleteNode(Key key) {
        root = deleteNode(root, key);
      }

      bool containNode(Key key) {
        return containNode(root, key);
      }

      Value *searchNode(Key key) {
        return searchNode(root, key);
      }

      void preOrderTravel() {
        preOrderTravel(root);
        std::cout << std::endl;
      }

      void inOrderTravel() {
        inOrderTravel(root);
        std::cout << std::endl;
      }

      void postOrderTravel() {
        postOrderTravel(root);
        std::cout << std::endl;
      }

      void levelOrderTravel() {
        levelOrderTravel(root);
        std::cout << std::endl;
      }

      Node *minimum() {
        return minimum(root);
      }

      Node *maximum() {
        return maximum(root);
      }

      void deleteMinNode() {
        root = deleteMinNode(root);
      }

      void deleteMaxNode() {
        root = deleteMaxNode(root);
      }

      int size() {
        return count;
      }

      bool isEmpty() {
        return count == 0;
      }

    private:
      Node *insertNode(Node *node, Key key, Value value) {
        if (node == nullptr) {
          count++;
          return new Node(key, value);
        }

        if (key < node->key) {
          node->left = insertNode(node->left, key, value);
        }else if (key > node->key) {
          node->right = insertNode(node->right, key, value);
        }else { // update
          node->value = value;
        }

        return node;
      }

      Node *minimum(Node *node) {
        if (node->left == nullptr)
          return node;
        return minimum(node->left);
      }

      Node *maximum(Node *node) {
        if (node->right == nullptr)
          return node;
        return maximum(node->right);
      }

      Node *deleteMinNode(Node *node) {
        if (node->left == nullptr) {
          Node *rightNode = node->right;
          delete node;
          count--;
          return rightNode;
        }
        return deleteMaxNode(node->left);
      }

      Node *deleteMaxNode(Node *node) {
        if (node->right == nullptr) {
          Node *leftNode = node->left;
          delete node;
          count--;
          return leftNode;
        }
        return deleteMaxNode(node->right);
      }

      Node *deleteNode(Node *node, Key key) {
        if (node == nullptr)
          return node;

        /// 分类不要分错....
        if (key < node->key) {
          node->left = deleteNode(node->left, key);
          return node;
        }else if (key > node->key) {
          node->right = deleteNode(node->right, key);
          return node;
        }else {
          /// 删除节点
          if (node->left == nullptr) {
            Node *rightNode = node->right;
            delete node;
            count--;
            return rightNode;
          } else if (node->right == nullptr) {
            Node *leftNode = node->left;
            delete node;
            count--;
            return leftNode;
          } else {
            Node *successor = new Node(minimum(node->right));
            /// 移除右边的最小值
            successor->right = deleteMinNode(node->right);
            successor->left = node->left;
            delete node;
            return successor;
          }
        }
      }

      void destroy(Node *node) {
        /// 后序遍历删除
        if (node == nullptr)
          return;
        destroy(node->left);
        destroy(node->right);
        delete node;
        count--;
      }

      void preOrderTravel(Node *node) {
        if (node == nullptr)
          return;
        std::cout << node->value << ", ";
        preOrderTravel(node->left);
        preOrderTravel(node->right);
      }

      void inOrderTravel(Node *node) {
        if (node == nullptr)
          return;
        inOrderTravel(node->left);
        std::cout << node->value << ", ";
        inOrderTravel(node->right);
      }

      void postOrderTravel(Node *node) {
        if (node == nullptr)
          return;
        postOrderTravel(node->left);
        postOrderTravel(node->right);
        std::cout << node->value << ", ";
      }

      void levelOrderTravel(Node *node) {
        if (node == nullptr)
          return;

        queue<Node *> q;
        q.push(node);

        while (!q.empty()) {
          Node *node = q.front();
          q.pop();

          std::cout << node->value << ", ";

          if (node->left)
            q.push(node->left);

          if (node->right)
            q.push(node->right);
        }
      }

      bool containNode(Node *node, Key key) {
        if (node == nullptr)
          return false;

        if (node->key == key)
          return true;
        else if (key < node->key)
          return containNode(node->left, key);
        else
          return containNode(node->right, key);
      }

      Value *searchNode(Node *node, Key key) {
        if (node == nullptr)
          return nullptr;
        if (key == node->key)
          return &node->value;
        else if (key < node->key)
          return searchNode(node->left, key);
        else
          return searchNode(node->right, key);
      }
  };
}

#endif // SORTTEST_BINARYSEARCHTREE_H
