/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    int i = 0;
    for (; i < strs[0].size(); ++i) {
      int j = 1;
      for (; j < strs.size() && i < strs[j].size() && strs[j][i] == strs[0][i];
           ++j) {
      }
      if (j < strs.size()) break;
    }
    return strs[0].substr(0, i);
  }
};
// @lc code=end
