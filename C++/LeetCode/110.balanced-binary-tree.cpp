/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
#include <algorithm>
#include <cmath>

class Solution {
 public:
  bool isBalanced(TreeNode* root) { return maxDepth(root) >= 0; }

 private:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    auto left_depth = maxDepth(root->left);
    if (left_depth < 0) return -1;
    auto right_depth = maxDepth(root->right);
    if (right_depth < 0) return -1;
    if (std::abs(left_depth - right_depth) > 1) return -1;
    return 1 + std::max(left_depth, right_depth);
  }
};
// @lc code=end
