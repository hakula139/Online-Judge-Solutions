/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
#include <vector>

class Solution {
 public:
  std::vector<TreeNode*> generateTrees(int n) { return generateTrees(1, n); }

 private:
  std::vector<TreeNode*> generateTrees(int begin, int end) {
    if (begin > end) return {nullptr};
    std::vector<TreeNode*> result;
    for (int i = begin; i <= end; ++i) {
      auto left_trees = generateTrees(begin, i - 1);
      auto right_trees = generateTrees(i + 1, end);
      for (auto left : left_trees) {
        for (auto right : right_trees) {
          result.push_back(new TreeNode{i, left, right});
        }
      }
    }
    return result;
  }
};
// @lc code=end
