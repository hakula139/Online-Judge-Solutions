/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> result;
    std::string path;
    if (root) dfs(result, path, root);
    return result;
  }

 private:
  void dfs(std::vector<std::string>& result, std::string& path,
           TreeNode* root) {
    if (path.size()) path += "->";
    path += std::to_string(root->val);
    if (!root->left && !root->right) {
      result.push_back(path);
    } else {
      if (root->left) dfs(result, path, root->left);
      if (root->right) dfs(result, path, root->right);
    }
    auto i = path.find_last_of('>');
    if (i != std::string::npos) {
      path.erase(i - 1);
    }
  }
};
// @lc code=end
