#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using std::queue;
using std::stoi;
using std::string;
using std::to_string;
using std::tuple;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
 public:
  using It = string::const_iterator;
  const int kNull = INT_MAX;

  // Encodes a tree to a single string
  string serialize(TreeNode* root) {
    string data;
    queue<TreeNode*> layer;
    layer.push(root);
    auto valid = true;
    while (valid) {
      valid = false;
      auto size = layer.size();
      while (size--) {
        auto cur = layer.front();
        layer.pop();
        if (cur) {
          data += to_string(cur->val) + ",";
          layer.push(cur->left);
          layer.push(cur->right);
          if (!valid) valid = cur->left || cur->right;
        } else {
          data += "null,";
        }
      }
    }
    return data;
  }

  // Decodes the encoded data to a tree
  TreeNode* deserialize(const string& data) {
    TreeNode* root = nullptr;
    queue<TreeNode*> layer;
    for (auto i = data.begin(); i < data.end();) {
      if (!root) {
        auto [val, new_i] = GetValue(i, data.end());
        i = new_i;
        root = (val != kNull) ? new TreeNode(val) : nullptr;
        layer.push(root);
        continue;
      }

      auto cur = layer.front();
      layer.pop();
      if (cur) {
        auto [left_val, left_new_i] = GetValue(i, data.end());
        i = left_new_i;
        auto [right_val, right_new_i] = GetValue(i, data.end());
        i = right_new_i;
        cur->left = (left_val != kNull) ? new TreeNode(left_val) : nullptr;
        cur->right = (right_val != kNull) ? new TreeNode(right_val) : nullptr;
        layer.push(cur->left);
        layer.push(cur->right);
      }
    }
    return root;
  }

 private:
  tuple<int, It> GetValue(It pos, It end) {
    string raw_val;
    for (; pos < end && *pos != ','; ++pos) raw_val += *pos;
    auto val = (raw_val.empty() || raw_val == "null") ? kNull : stoi(raw_val);
    auto new_pos = ++pos < end ? pos : end;
    return {val, new_pos};
  }
};
