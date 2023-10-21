/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
#include <deque>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> result;
    std::deque<TreeNode*> q;
    if (root) q.push_back(root);
    bool is_reverse_dir = false;
    while (q.size()) {
      result.push_back({});
      for (int i = q.size(); i > 0; --i) {
        if (is_reverse_dir) {
          auto node = q.back();
          result.back().push_back(node->val);
          if (node->right) q.push_front(node->right);
          if (node->left) q.push_front(node->left);
          q.pop_back();
        } else {
          auto node = q.front();
          result.back().push_back(node->val);
          if (node->left) q.push_back(node->left);
          if (node->right) q.push_back(node->right);
          q.pop_front();
        }
      }
      is_reverse_dir = !is_reverse_dir;
    }
    return result;
  }
};
// @lc code=end
