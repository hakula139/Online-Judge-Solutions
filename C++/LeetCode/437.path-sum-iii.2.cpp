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
#include <unordered_map>

class Solution {
 public:
  int pathSum(TreeNode* root, int target_sum) {
    std::unordered_map<int64_t, int> sums;
    sums[0] = 1;
    return dfs(root, sums, 0, target_sum);
  }

 private:
  int dfs(TreeNode* root, std::unordered_map<int64_t, int>& sums,
          int64_t cur_sum, int64_t target_sum) {
    if (!root) return 0;
    cur_sum += root->val;
    auto it = sums.find(cur_sum - target_sum);
    auto result = it == sums.end() ? 0 : it->second;

    ++sums[cur_sum];
    result += dfs(root->left, sums, cur_sum, target_sum);
    result += dfs(root->right, sums, cur_sum, target_sum);
    if (--sums[cur_sum] == 0) {
      sums.erase(cur_sum);
    }
    return result;
  }
};
// @lc code=end
