#include <vector>

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

class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return {};

    auto depth = 0;
    vector<TreeNode *> cur_level{root};
    vector<vector<int>> result;

    while (!cur_level.empty()) {
      vector<int> cur_vals;
      if (depth % 2) {
        for (auto i = cur_level.rbegin(); i < cur_level.rend(); ++i) {
          cur_vals.push_back((*i)->val);
        }
      } else {
        for (auto i = cur_level.begin(); i < cur_level.end(); ++i) {
          cur_vals.push_back((*i)->val);
        }
      }
      result.push_back(cur_vals);

      vector<TreeNode *> next_level;
      for (const auto &node : cur_level) {
        if (node->left) next_level.push_back(node->left);
        if (node->right) next_level.push_back(node->right);
      }
      cur_level = next_level;
      ++depth;
    }

    return result;
  }
};
