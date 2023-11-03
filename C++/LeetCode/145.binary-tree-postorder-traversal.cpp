/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* prev = nullptr;
    while (root || stack.size()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      auto node = stack.top();
      if (node->right && node->right != prev) {
        root = node->right;
      } else {
        result.push_back(node->val);
        prev = node;
        stack.pop();
      }
    }
    return result;
  }
};
// @lc code=end
