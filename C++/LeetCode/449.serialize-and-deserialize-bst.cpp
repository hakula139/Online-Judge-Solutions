/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
#include <algorithm>
#include <string>
#include <vector>

class Codec {
 public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode* root) {
    std::string result;
    serialize(result, root);
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(const std::string& data) {
    TreeNode* root = nullptr;
    auto values = split(data);
    deserialize(root, values.cbegin(), values.cend());
    return root;
  }

 private:
  using It = std::vector<int>::const_iterator;

  static constexpr char kDelim = ' ';

  void serialize(std::string& buf, TreeNode* root) {
    if (!root) return;
    buf += std::to_string(root->val);
    buf += kDelim;
    serialize(buf, root->left);
    serialize(buf, root->right);
  }

  void deserialize(TreeNode*& root, It begin, It end) {
    if (begin >= end) return;
    auto root_val = *begin;
    root = new TreeNode{root_val};
    auto it = std::find_if(begin, end, [&](int val) { return val > root_val; });
    deserialize(root->left, ++begin, it);
    deserialize(root->right, it, end);
  }

  std::vector<int> split(const std::string& data) {
    std::vector<int> result;
    int val = 0;
    for (auto c : data) {
      if (c == kDelim) {
        result.push_back(val);
        val = 0;
      } else {
        val = val * 10 + c - '0';
      }
    }
    return result;
  }
};
// @lc code=end
