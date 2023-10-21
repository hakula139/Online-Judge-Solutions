/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> result;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (q.size()) {
      result.push_back({});
      for (int i = q.size(); i > 0; --i) {
        auto node = q.front();
        result.back().push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        q.pop();
      }
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
