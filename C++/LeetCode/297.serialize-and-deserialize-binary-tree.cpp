/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
#include <queue>
#include <string>

class Codec {
 public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    std::string result;
    std::queue<TreeNode*> q;
    if (root) q.push(root);
    while (q.size()) {
      for (int i = q.size(); i > 0; --i) {
        auto node = q.front();
        if (node) {
          result += std::to_string(node->val);
          result += ' ';
          q.push(node->left);
          q.push(node->right);
        } else {
          result += '/';
        }
        q.pop();
      }
    }
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(const std::string& data) {
    TreeNode* root = nullptr;
    std::queue<TreeNode*> q;
    int val = 0;
    bool is_positive = true;
    bool is_left = true;
    for (auto c : data) {
      TreeNode* node = nullptr;
      switch (c) {
        case '-':
          is_positive = false;
          break;
        case ' ':
          node = new TreeNode{is_positive ? val : -val};
          val = 0;
          is_positive = true;
          [[fallthrough]];
        case '/':
          if (q.empty()) {
            root = node;
          } else {
            auto parent = q.front();
            if (is_left) {
              parent->left = node;
              is_left = false;
            } else {
              parent->right = node;
              is_left = true;
              q.pop();
            }
          }
          if (node) q.push(node);
          break;
        default:
          val = val * 10 + c - '0';
          break;
      }
    }
    return root;
  }
};
// @lc code=end
