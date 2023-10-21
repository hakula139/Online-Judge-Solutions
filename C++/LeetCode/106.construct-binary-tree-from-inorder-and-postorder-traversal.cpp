/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
  using RevIt = std::vector<int>::const_reverse_iterator;

  TreeNode* buildTree(
      const std::vector<int>& inorder, const std::vector<int>& postorder) {
    return buildTree(
        postorder.rbegin(), postorder.rend(), inorder.begin(), inorder.end());
  }

 private:
  TreeNode* buildTree(
      RevIt post_rbegin, RevIt post_rend, It in_begin, It in_end) {
    if (post_rbegin >= post_rend) return nullptr;
    auto root = new TreeNode{*post_rbegin};
    auto root_it = std::find(in_begin, in_end, root->val);
    auto right_size = in_end - root_it - 1;
    auto left_rbegin = post_rbegin + right_size + 1;
    root->left = buildTree(left_rbegin, post_rend, in_begin, root_it);
    root->right = buildTree(post_rbegin + 1, left_rbegin, root_it + 1, in_end);
    return root;
  }
};
// @lc code=end
