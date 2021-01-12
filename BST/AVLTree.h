/**********************************
 * File:     AVLTree.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/11
 ***********************************/

#ifndef BST_AVLTREE_H
#define BST_AVLTREE_H
#include <vector>

namespace BST {
  template <typename Key, typename Value>
  class AVLTree {
    class Node {
    public:
      Key key;
      Value value;
      Node *left;
      Node *right;
      int height;
      Node(Key key, Value value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        height = 1; /// 默认生成的结点高度为1
      }

      Node(Node *node) {
        this->key = node->key;
        this->value = node->value;
        this->left = node->left;
        this->right = node->right;
        this->height = node->height;
      }
    };
    Node *root;
    int count;
  public:
    AVLTree() {
      root = nullptr;
      count = 0;
    }

    ~AVLTree() {
      destroy();
    }

    bool isEmpty() {
      return count == 0;
    }

    int size() {
      return count;
    }

    int height() {
      assert(root);
      return root->height;
    }

    void insert(Key key, Value value) {
      root = insert(root, key, value);
    }

    void erase(Key key) {
      root = erase(root, key);
    }

    bool contain(Key key) {
      return contain(root, key);
    }

    Value search(Key key) {
      return search(root, key);
    }

    void destroy() {
      destroy(root);
    }

    bool isBST() {
      assert(root);
      std::vector<Value> v(count);
      inOrderTravel(root, v);
      for (int i = 1; i < count; ++i)
        if (v[i-1] > v[i])
          return false;
      return true;
    }

    bool isBalance() {
      return isBalance(root);
    }

    Node *minimum() {
      return minimum(root);
    }

    Node *maximum() {
      return maximum(root);
    }

    void inOrderTravel() {
      std::cout << "inOrderTravel" << std::endl;
      inOrderTravel(root);
      std::cout << std::endl;
    }

    void preOrderTravel() {
      std::cout << "preOrderTravel" << std::endl;
      preOrderTravel(root);
      std::cout << std::endl;
    }
  private:
    /**
     *        y                           x
     *      x   T4                    z      y
     *    z  T3         ==>         T1 T2  T3 T4
     *  T1 T2
     */
    Node *rightRotate(Node *y) {
        Node *x = y->left;
        y->left = x->right;
        x->right = y;
        y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
        x->height = 1 + std::max(getNodeHeight(x->left), getNodeHeight(x->right));
        return x;
    }

    /**
     *       y
     *    T1    x                           x
     *       T2    z        ==>          y      z
     *          T3  T4                T1  T2  T3 T4
     */
    Node *leftRotate(Node *y) {
       Node *x = y->right;
       y->right = x->left;
       x->left = y;
       y->height = 1 + std::max(getNodeHeight(y->left), getNodeHeight(y->right));
       x->height = 1 + std::max(getNodeHeight(x->left), getNodeHeight(x->right));
       return x;
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

    Node *insert(Node *node, Key key, Value value) {
      if (node == nullptr) {
        count++;
        return new Node(key, value);
      }
      if (key < node->key) {
        node->left = insert(node->left, key, value);
      }else if (key > node->key) {
        node->right = insert(node->right, key, value);
      }else {
        node->value = value;
      }

      /// 更新结点高度
      node->height = 1 + std::max(getNodeHeight(node->left), getNodeHeight(node->right));
      int balanceFactor = getBalanceFactor(node);

      /// 1. ll
      if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0) {
        return rightRotate(node);
      }
      /// 2. rr
      if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0) {
        return leftRotate(node);
      }
      /// 3. lr
      /**
       *           y                     y
       *        x    T4               z     T4                z
       *     T1   z         ==>     x   T3        =>      x       y
       *       T2  T3             T1 T2                 T1 T2   T3 T4
       */
      if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }

      /// 4. rl
      /**
       *          y                   y                           z
       *       T1   x       =>     T1   z           =>        y       x
       *          z   T4              T2  x                 T1 T2   T3 T4
       *        T2 T3                   T3  T4
       */
      if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }

      return node;
    }

    Node *erase(Node *node, Key key) {
      if (node == nullptr)
        return node;

      Node *retNode;
      if (key < node->key) {
        node->left = erase(node->left, key);
        retNode = node;
      }else if (key > node->key) {
        node->right = erase(node->right, key);
        retNode = node;
      }else {
        if (node->left == nullptr) {
          Node *rightNode = node->right;
          delete node;
          count--;
          retNode = rightNode;
        } else if (node->right == nullptr) {
          Node *leftNode = node->left;
          delete node;
          count--;
          retNode = leftNode;
        } else {
          Node *successor = new Node(minimum(node->right));
          successor->right = erase(node->right, successor->key);
          successor->left = node->left;
          delete node;
          retNode = successor;
        }
      }
      if (retNode == nullptr)
        return retNode;

      /// 更新结点高度
      retNode->height = 1 + std::max(getNodeHeight(retNode->left), getNodeHeight(retNode->right));
      int balanceFactor = getBalanceFactor(retNode);

      /// 1. ll
      if (balanceFactor > 1 && getBalanceFactor(retNode->left) >= 0) {
        return rightRotate(retNode);
      }
      /// 2. rr
      if (balanceFactor < -1 && getBalanceFactor(retNode->right) <= 0) {
        return leftRotate(retNode);
      }
      /// 3. lr
      /**
       *           y                     y
       *        x    T4               z     T4                z
       *     T1   z         ==>     x   T3        =>      x       y
       *       T2  T3             T1 T2                 T1 T2   T3 T4
       */
      if (balanceFactor > 1 && getBalanceFactor(retNode->left) < 0) {
        retNode->left = leftRotate(retNode->left);
        return rightRotate(retNode);
      }

      /// 4. rl
      /**
       *          y                   y                           z
       *       T1   x       =>     T1   z           =>        y       x
       *          z   T4              T2  x                 T1 T2   T3 T4
       *        T2 T3                   T3  T4
       */
      if (balanceFactor < -1 && getBalanceFactor(retNode->right) > 0) {
        retNode->right = rightRotate(retNode->right);
        return leftRotate(retNode);
      }
      return retNode;
    }

    bool contain(Node *node, Key key) {
      if (node == nullptr)
        return false;
      if (key < node->key)
        return contain(node->left, key);
      else if (key > node->key)
        return contain(node->right, key);
      else {
        return true;
      }
    }

    void inOrderTravel(Node *node) {
      if (node == nullptr)
        return;
      inOrderTravel(node->left);
      std::cout << node->value << ", ";
      inOrderTravel(node->right);
    }

    void inOrderTravel(Node *node, std::vector<Value> &vec) {
      if (node == nullptr)
        return;
      inOrderTravel(node->left, vec);
      vec.push_back(node->value);
      inOrderTravel(node->right, vec);
    }

    void preOrderTravel(Node *node) {
      if (node == nullptr)
        return;
      std::cout << node->value << ", ";
      preOrderTravel(node->left);
      preOrderTravel(node->right);
    }

    void destroy(Node *node) {
      if (node == nullptr)
        return;
      destroy(node->left);
      destroy(node->right);
      delete node;
      count = 0;
    }

    bool isBalance(Node *node) {
      if (node == nullptr)
        return true;
      if (getNodeHeight(node->left) - getNodeHeight(node->right) > 1
          || getNodeHeight(node->left) - getNodeHeight(node->right) < -1)
        return false;
      return isBalance(node->left) && isBalance(node->right);
    }

    int getNodeHeight(Node *node) {
      if (node == nullptr)
        return 0;
      return node->height;
    }

    int getBalanceFactor(Node *node) {
      if (node == nullptr)
        return 0;
      return getNodeHeight(node->left) - getNodeHeight(node->right);
    }

    Value search(Node *node, Key key) {
      if (node == nullptr)
        return 0;
      if (key == node->key)
        return node->value;
      else if (key < node->key)
        return search(node->left, key);
      else
        return search(node->right, key);
    }
  };
}

#endif // BST_AVLTREE_H
