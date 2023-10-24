/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    auto left_depth = minDepth(root->left);
    auto right_depth = minDepth(root->right);
    if (!left_depth) return 1 + right_depth;
    if (!right_depth) return 1 + left_depth;
    return 1 + std::min(left_depth, right_depth);
  }
};
// @lc code=end
