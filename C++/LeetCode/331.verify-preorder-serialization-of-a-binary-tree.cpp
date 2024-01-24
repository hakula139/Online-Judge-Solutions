/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool isValidSerialization(const std::string& preorder) {
    int depth = 0;
    for (int i = 0; i < preorder.size(); ++i) {
      if (preorder[i] == ',') {
        ++depth;
      } else if (preorder[i] == '#') {
        --depth, ++i;
        if (depth < 0 && i < preorder.size()) {
          return false;
        }
      }
    }
    return depth == -1;
  }
};
// @lc code=end
