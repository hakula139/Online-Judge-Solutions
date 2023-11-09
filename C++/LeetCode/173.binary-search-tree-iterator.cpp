/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
#include <stack>

class BSTIterator {
 public:
  explicit BSTIterator(TreeNode* root) { insert(root); }

  int next() {
    auto root = stack_.top();
    stack_.pop();
    insert(root->right);
    return root->val;
  }

  bool hasNext() const { return !stack_.empty(); }

 private:
  void insert(TreeNode* root) {
    while (root) {
      stack_.push(root);
      root = root->left;
    }
  }

  std::stack<TreeNode*> stack_;
};
// @lc code=end
