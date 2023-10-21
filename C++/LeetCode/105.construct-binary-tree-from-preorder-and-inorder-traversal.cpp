/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
#include <algorithm>
#include <vector>

class Solution {
 public:
  using It = std::vector<int>::const_iterator;

  TreeNode* buildTree(
      const std::vector<int>& preorder, const std::vector<int>& inorder) {
    return buildTree(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }

 private:
  TreeNode* buildTree(It pre_begin, It pre_end, It in_begin, It in_end) {
    if (pre_begin >= pre_end) return nullptr;
    auto root = new TreeNode{*pre_begin};
    auto root_it = std::find(in_begin, in_end, root->val);
    auto left_size = root_it - in_begin;
    auto right_begin = pre_begin + left_size + 1;
    root->left = buildTree(pre_begin + 1, right_begin, in_begin, root_it);
    root->right = buildTree(right_begin, pre_end, root_it + 1, in_end);
    return root;
  }
};
// @lc code=end
