/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class Solution {
 public:
  void flatten(TreeNode* root) {
    while (root) {
      if (root->left) {
        auto prev = root->left;
        while (prev->right) {
          prev = prev->right;
        }
        prev->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      root = root->right;
    }
  }
};
// @lc code=end
