class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  explicit Node(int _val)
      : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root) Connect(root->left, root->right);
    return root;
  }

 private:
  void Connect(Node* left, Node* right) {
    if (!left || !right) return;
    left->next = right;
    Connect(left->left, left->right);
    Connect(left->right, right->left);
    Connect(right->left, right->right);
  }
};
