/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
#include <utility>

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;
    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
    return root;
  }
};
// @lc code=end
