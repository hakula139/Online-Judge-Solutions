/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
  bool hasPathSum(TreeNode* root, int target_sum) {
    if (!root) return false;
    target_sum -= root->val;
    return !target_sum && !root->left && !root->right ||
           hasPathSum(root->left, target_sum) ||
           hasPathSum(root->right, target_sum);
  }
};
// @lc code=end
