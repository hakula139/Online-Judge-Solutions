/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
  int countNodes(TreeNode* root) {
    int result = 0;
    auto left_depth = getDepth(root);
    while (root) {
      --left_depth;
      auto right_depth = getDepth(root->right);
      if (left_depth == right_depth) {
        result += 1 << left_depth;
        root = root->right;
        left_depth = right_depth;
      } else {
        result += 1 << right_depth;
        root = root->left;
      }
    }
    return result;
  }

 private:
  int getDepth(TreeNode* root) {
    int depth = 0;
    while (root) {
      root = root->left;
      ++depth;
    }
    return depth;
  }
};
// @lc code=end
