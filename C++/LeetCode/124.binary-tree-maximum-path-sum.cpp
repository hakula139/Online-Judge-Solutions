/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
  int maxPathSum(TreeNode* root) {
    int max_path = INT_MIN;
    maxPathSum(root, max_path);
    return max_path;
  }

 private:
  int maxPathSum(TreeNode* root, int& max_path) {
    if (!root) return 0;
    auto left_max_path = std::max(maxPathSum(root->left, max_path), 0);
    auto right_max_path = std::max(maxPathSum(root->right, max_path), 0);
    max_path = std::max(root->val + left_max_path + right_max_path, max_path);
    return root->val + std::max(left_max_path, right_max_path);
  }
};
// @lc code=end
