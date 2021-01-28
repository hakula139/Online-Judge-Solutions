#include <iostream>
#include <string>
#include <vector>

template <class T>
class BinaryTree;

template <class T>
class Node {
 public:
  Node() : val_(0), left_(nullptr), right_(nullptr) {}
  explicit Node(const T& val) : val_(val), left_(nullptr), right_(nullptr) {}
  Node(const T& val, Node* left, Node* right)
      : val_(val), left_(left), right_(right) {}

  friend class BinaryTree<T>;

 private:
  T val_;
  Node* left_;
  Node* right_;
};

template <class T>
class BinaryTree {
 public:
  static const size_t kMaxSize = 100;

  BinaryTree() : root_(nullptr), cur_depth_(0) { prev_.reserve(kMaxSize + 1); }
  ~BinaryTree() { DeleteTree(); }

  void AddNode(const std::string& node) {
    size_t depth = node.length() - 1;
    T val = node.back();

    if (!depth) {
      if (root_) {
        DeleteTree();
        prev_.clear();
      }
      root_ = new Node<T>(val);
      prev_.push_back(root_);
      cur_depth_ = 0;
      return;
    }

    if (depth == cur_depth_ + 1) {
      Node<T>* node_ = nullptr;
      if (val != '*') node_ = new Node<T>(val);
      prev_[cur_depth_]->left_ = node_;
      prev_[depth] = node_;
      cur_depth_ = depth;
    } else /* depth <= cur_depth_ */ {
      auto node_ = new Node<T>(val);
      prev_[depth - 1]->right_ = node_;
      prev_[depth] = node_;
      cur_depth_ = depth;
    }
  }

  void Preorder() { Preorder(root_); }
  void Inorder() { Inorder(root_); }
  void Postorder() { Postorder(root_); }
  void DeleteTree() { DeleteTree(root_); }

 protected:
  void Preorder(Node<T>* root) {
    if (!root) return;
    Print(root);
    Preorder(root->left_);
    Preorder(root->right_);
  }

  void Inorder(Node<T>* root) {
    if (!root) return;
    Inorder(root->left_);
    Print(root);
    Inorder(root->right_);
  }

  void Postorder(Node<T>* root) {
    if (!root) return;
    Postorder(root->left_);
    Postorder(root->right_);
    Print(root);
  }

  void Print(Node<T>* node) {
    if (!node) return;
    std::cout << node->val_;
  }

  void DeleteTree(Node<T>* node) {
    if (!node) return;
    if (node->left_) DeleteTree(node->left_);
    if (node->right_) DeleteTree(node->right_);
    delete node;
  }

 private:
  Node<T>* root_;
  // This vector stores the last node visited at each layer.
  std::vector<Node<T>*> prev_;
  size_t cur_depth_;
};

int main() {
  size_t n;
  std::cin >> n;
  std::cin.ignore(255, '\n');
  while (n--) {
    std::string node;
    BinaryTree<char> tree;
    while (std::getline(std::cin, node)) {
      if (node == "0") break;
      tree.AddNode(node);
    }
    tree.Preorder();
    std::cout << '\n';
    tree.Postorder();
    std::cout << '\n';
    tree.Inorder();
    std::cout << "\n\n";
  }
  return 0;
}
