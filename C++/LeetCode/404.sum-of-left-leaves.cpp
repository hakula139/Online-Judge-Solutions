/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int sumOfLeftLeaves(TreeNode* root) { return sumOfLeftLeaves(root, false); }

 private:
  int sumOfLeftLeaves(TreeNode* root, bool is_left) {
    if (!root) return 0;
    if (!root->left && !root->right) {
      return is_left ? root->val : 0;
    }
    return sumOfLeftLeaves(root->left, true) +
           sumOfLeftLeaves(root->right, false);
  }
};
// @lc code=end
