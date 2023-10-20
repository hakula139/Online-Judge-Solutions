/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
  void recoverTree(TreeNode* root) {
    TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
    inorderTraverse(root, prev, first, second);
    std::swap(first->val, second->val);
  }

 private:
  void inorderTraverse(
      TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& second) {
    if (!root) return;
    inorderTraverse(root->left, prev, first, second);
    if (prev && root->val <= prev->val) {
      if (!first) first = prev;
      second = root;
    }
    prev = root;
    inorderTraverse(root->right, prev, first, second);
  }
};
// @lc code=end
