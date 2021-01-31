#include <algorithm>
#include <vector>

using std::find;
using std::vector;
using It = const vector<int>::const_iterator;

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
  TreeNode *buildTree(const vector<int> &preorder, const vector<int> &inorder) {
    return BuildTree(
        preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }

 private:
  TreeNode *BuildTree(It pre_begin, It pre_end, It in_begin, It in_end) {
    if (pre_begin == pre_end) return nullptr;
    if (pre_end - pre_begin == 1) return new TreeNode(*pre_begin);

    auto root_pos = find(in_begin, in_end, *pre_begin);
    auto left_size = root_pos - in_begin;

    return new TreeNode(
        *pre_begin,
        BuildTree(pre_begin + 1, pre_begin + left_size + 1, in_begin, root_pos),
        BuildTree(pre_begin + left_size + 1, pre_end, root_pos + 1, in_end));
  }
};
