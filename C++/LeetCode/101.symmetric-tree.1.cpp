/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
  }

 private:
  bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left) return !right;
    if (!right) return !left;
    return left->val == right->val && isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};
// @lc code=end
