/**********************************
 * File:     RBTree.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/1/12
 ***********************************/

#ifndef BST_RBTREE_H
#define BST_RBTREE_H

/**
 * 红黑树是和2-3树是等价的，理解红黑树可以从2-3树去理解(融合和分裂)
 * 满足下面5条性质的树为红黑树
 * 1. 所有节点非黑即红
 * 2. 跟结点是黑色
 * 3. 所有空节点是黑色
 * 4. 红色结点的孩子是黑色
 * 5. 满足绝对黑平衡，从跟结点到叶子结点的所有路径中黑色结点的数目一致
 */

namespace BST {
  template <typename Key, typename Value>
  class RBTree {
  private:
    enum class Color {
      black,
      red
    };
    class Node {
    public:
      Key key;
      Value value;
      Node *left;
      Node *right;
      Color color;
      Node(Key key, Value value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
        color = Color::red;
      }
      Node(Node *node) {
        this->key = node->key;
        this->value = node->value;
        this->left = node->left;
        this->right = node->right;
        this->color = node->color;
      }
    };
    Node *root;
    int count;
  public:
    RBTree() {
      root = nullptr;
      count = 0;
    }
    ~RBTree() {
      destroy();
    }
    bool isEmpty() {
      return count == 0;
    }
    int size() {
      return count;
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

    Node *minimum() {
      return minimum(root);
    }

    void destroy() {
      destroy(root);
      count = 0;
    }

    void preOrderTravel() {
      std::cout << "preOrderTravel" << std::endl;
      preOrderTravel(root);
      std::cout << std::endl;
    }

    void inOrderTravel() {
      std::cout << "inOrderTravel" << std::endl;
      inOrderTravel(root);
      std::cout << std::endl;
    }

  private:
    /**
     *    Node        左旋转              X
     *    /   \       ===>             /   \
     *   T1    X                     Node   T3
     *        /  \                   /  \
     *       T2  T3                T1   T2
     */
    Node *leftRotate(Node *node) {
        Node *x = node->right;
        node->right = x->left;
        x->left = node;

        x->color = node->color;   /// 左旋保持跟结点颜色不变
        node->color = Color::red;
        return x;
    }

    /**
     *      Node                X
     *      /  \       右旋转   /  \
     *     X   T3      =>    T1   Node
     *    / \                     /  \
     *   T1 T2                   T2  T3
     */
    Node *rightRotate(Node *node) {
        Node *x = node->left;
        node->left = x->right;
        x->right = node;

        x->color = node->color;   /// 旋转时根节点颜色传递
        node->color = Color::red;
        return x;
    }

    void flipColors(Node *node) {
        node->color = Color::red;
        node->left->color = Color::black;
        node->right->color = Color::black;
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

      /// 红黑树调整平衡
      /**
       *     black     black        black
       *     /          /           /          black             red
       *   red    ->  red    ->    red   ->    /   \     ->     /    \
       *                 \         /         red   red        black  black
       *                 red      red
       */

      if (isRed(node->right) && !isRed(node->left))
        node = leftRotate(node);

      if (isRed(node->left) && isRed(node->left->left))
        node = rightRotate(node);

      if (isRed(node->left) && isRed(node->right))
        flipColors(node);

      return node;
    }

    Node *erase(Node *node, Key key) {
      if (node == nullptr)
        return node;
      if (key < node->key) {
        node->left = erase(node->left, key);
        return node;
      }else if (key > node->key) {
        node->right = erase(node->right, key);
        return node;
      }else {
        if (node->left == nullptr) {
          Node *rightNode = node->right;
          delete node;
          count--;
          return rightNode;
        }else if (node->right == nullptr) {
          Node *leftNode = node->left;
          delete node;
          count--;
          return leftNode;
        }else {
          Node *successor = new Node(minimum(node->right));
          successor->right = erase(node->right, successor->key);
          successor->left = node->left;
          delete node;
          return successor;
        }
      }
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

    Node *minimum(Node *node) {
      if (node->left == nullptr)
        return node;
      return minimum(node->left);
    }

    bool isRed(Node *node) {
      if (node == nullptr)
        return false;
      return node->color == Color::red;
    }

    void destroy(Node *node) {
      if (node == nullptr)
        return;
      destroy(node->left);
      destroy(node->right);
      delete node;
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

#endif // BST_RBTREE_H
