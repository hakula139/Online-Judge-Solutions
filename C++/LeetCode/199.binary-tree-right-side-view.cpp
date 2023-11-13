/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
#include <queue>
#include <vector>

class Solution {
 public:
  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (q.size()) {
      result.push_back(q.front()->val);
      for (int i = q.size(); i > 0; --i) {
        auto node = q.front();
        if (node->right) q.push(node->right);
        if (node->left) q.push(node->left);
        q.pop();
      }
    }
    return result;
  }
};
// @lc code=end
