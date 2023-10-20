/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
class Solution {
 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p) return !q;
    if (!q) return !p;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
// @lc code=end
