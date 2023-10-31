/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbers(TreeNode* root) { return sumNumbers(root, 0); }

 private:
  int sumNumbers(TreeNode* root, int prev) {
    if (!root) return 0;
    int prefix = prev * 10 + root->val;
    if (!root->left && !root->right) return prefix;
    return sumNumbers(root->left, prefix) + sumNumbers(root->right, prefix);
  }
};
// @lc code=end
