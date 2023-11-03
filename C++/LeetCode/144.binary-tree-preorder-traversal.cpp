/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    while (root || stack.size()) {
      while (root) {
        result.push_back(root->val);
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      root = root->right;
    }
    return result;
  }
};
// @lc code=end
