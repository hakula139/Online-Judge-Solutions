#include <stack>
#include <vector>

using std::stack;
using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// Iterative solution
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    auto cur = root;
    while (!s.empty() || cur) {
      while (cur) {
        s.push(cur);
        cur = cur->left;
      }
      cur = s.top();
      s.pop();
      result.push_back(cur->val);
      cur = cur->right;
    }
    return result;
  }
};
