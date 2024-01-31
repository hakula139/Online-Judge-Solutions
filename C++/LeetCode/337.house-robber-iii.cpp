/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
#include <utility>

class Solution {
 public:
  int rob(TreeNode* root) {
    auto [sum_linked, sum_unlinked] = maxSum(root);
    return std::max(sum_linked, sum_unlinked);
  }

 private:
  std::pair<int, int> maxSum(TreeNode* node) {
    if (!node) return {0, 0};
    auto [left_sum_linked, left_sum_unlinked] = maxSum(node->left);
    auto [right_sum_linked, right_sum_unlinked] = maxSum(node->right);
    auto sum_linked = node->val + left_sum_unlinked + right_sum_unlinked;
    auto sum_unlinked =
        std::max(left_sum_linked, left_sum_unlinked) +
        std::max(right_sum_linked, right_sum_unlinked);
    return {sum_linked, sum_unlinked};
  }
};
// @lc code=end
