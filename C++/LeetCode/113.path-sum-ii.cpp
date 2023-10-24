/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
  std::vector<std::vector<int>> pathSum(TreeNode* root, int target_sum) {
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    pathSum(result, path, root, target_sum);
    return result;
  }

 private:
  void pathSum(std::vector<std::vector<int>>& result, std::vector<int>& path,
               TreeNode* root, int target_sum) {
    if (!root) return;
    path.push_back(root->val);
    target_sum -= root->val;
    if (!target_sum && !root->left && !root->right) {
      result.push_back(path);
    } else {
      pathSum(result, path, root->left, target_sum);
      pathSum(result, path, root->right, target_sum);
    }
    path.pop_back();
  }
};
// @lc code=end
