/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
  bool isValidBST(TreeNode* root) { return isValidBST(root, nullptr, nullptr); }

 private:
  bool isValidBST(TreeNode* root, TreeNode* left_min, TreeNode* right_max) {
    if (!root) return true;
    auto left = root->left, right = root->right;
    if (left) {
      if (left->val >= root->val) return false;
      if (left_min && left->val <= left_min->val) return false;
      if (!isValidBST(left, left_min, root)) return false;
    }
    if (right) {
      if (right->val <= root->val) return false;
      if (right_max && right->val >= right_max->val) return false;
      if (!isValidBST(right, root, right_max)) return false;
    }
    return true;
  }
};
// @lc code=end
