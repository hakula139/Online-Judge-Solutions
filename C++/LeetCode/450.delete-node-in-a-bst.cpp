/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    if (root->val < key) {
      root->right = deleteNode(root->right, key);
      return root;
    }
    if (root->val > key) {
      root->left = deleteNode(root->left, key);
      return root;
    }

    if (!root->left) {
      auto right = root->right;
      delete root;
      return right;
    }
    if (!root->right) {
      auto left = root->left;
      delete root;
      return left;
    }

    auto node = root->right;
    while (node->left) {
      node = node->left;
    }
    root->val = node->val;
    root->right = deleteNode(root->right, node->val);
    return root;
  }
};
// @lc code=end
