/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
 */

#include <vector>

struct Node {
  int val;
  std::vector<Node*> children;
  Node() {}
  explicit Node(int val) : val{val} {}
  Node(int val, const std::vector<Node*>& children)
      : val{val}, children{children} {}
};

// @lc code=start
#include <queue>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> result;
    std::queue<Node*> level;
    if (root) level.push(root);
    while (level.size()) {
      result.emplace_back();
      for (int i = level.size(); i > 0; --i) {
        auto node = level.front();
        level.pop();
        result.back().push_back(node->val);
        for (auto child : node->children) {
          level.push(child);
        }
      }
    }
    return result;
  }
};
// @lc code=end
