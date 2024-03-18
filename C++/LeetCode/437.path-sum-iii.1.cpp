/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
#include <cstdint>

class Solution {
 public:
  int pathSum(TreeNode* root, int target_sum) {
    if (!root) return 0;
    int result = 0;
    dfs(result, root, target_sum);
    result += pathSum(root->left, target_sum);
    result += pathSum(root->right, target_sum);
    return result;
  }

 private:
  void dfs(int& result, TreeNode* root, int64_t target_sum) {
    if (!root) return;
    if (root->val == target_sum) {
      ++result;
    }
    target_sum -= root->val;
    dfs(result, root->left, target_sum);
    dfs(result, root->right, target_sum);
  }
};
// @lc code=end
