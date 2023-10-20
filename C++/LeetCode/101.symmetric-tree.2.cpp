/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
#include <tuple>

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    std::stack<std::tuple<TreeNode*, TreeNode*>> stack;
    auto left = root->left, right = root->right;
    while (left || right || stack.size()) {
      while (left) {
        if (!right) return false;
        stack.emplace(left, right);
        left = left->left, right = right->right;
      }
      if (right) return false;
      std::tie(left, right) = stack.top();
      stack.pop();
      if (left->val != right->val) return false;
      left = left->right, right = right->left;
    }
    return true;
  }
};
// @lc code=end
