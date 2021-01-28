#include <iostream>

template <class T>
class BinarySearchTree;

template <class T>
class Node {
 public:
  Node() : val_(0), left_(nullptr), right_(nullptr) {}
  explicit Node(const T& val) : val_(val), left_(nullptr), right_(nullptr) {}
  Node(const T& val, Node* left, Node* right)
      : val_(val), left_(left), right_(right) {}

  friend class BinarySearchTree<T>;

 private:
  T val_;
  Node* left_;
  Node* right_;
};

template <class T>
class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr) {}
  ~BinarySearchTree() { DeleteTree(root_); }

  void Add(const T& val) {
    Node<T>* cur = root_;
    Node<T>* prev = nullptr;
    Direction origin = LEFT;
    while (cur) {
      prev = cur;
      if (val < cur->val_) {
        cur = cur->left_;
        origin = LEFT;
      } else if (val > cur->val_) {
        cur = cur->right_;
        origin = RIGHT;
      } else {
        return;
      }
    }
    auto new_node = new Node<T>(val);
    if (!prev)
      root_ = new_node;
    else if (origin == LEFT)
      prev->left_ = new_node;
    else /* origin == RIGHT */
      prev->right_ = new_node;
  }

  void Preorder() { Preorder(root_); }
  void DeleteTree() { DeleteTree(root_); }

 protected:
  void Preorder(Node<T>* root) {
    if (!root) return;
    Print(root);
    Preorder(root->left_);
    Preorder(root->right_);
  }

  void Print(Node<T>* node) {
    if (!node) return;
    std::cout << node->val_ << ' ';
  }

  void DeleteTree(Node<T>* node) {
    if (!node) return;
    if (node->left_) DeleteTree(node->left_);
    if (node->right_) DeleteTree(node->right_);
    delete node;
  }

  // Child is Parent->left_ or Parent->right_
  enum Direction { LEFT, RIGHT };

 private:
  Node<T>* root_;
};

int main() {
  BinarySearchTree<int> bst;
  int tmp = 0;
  while (std::cin >> tmp) bst.Add(tmp);
  bst.Preorder();
  std::cout << '\n';
  return 0;
}
