/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool isSubsequence(const std::string& s, const std::string& t) {
    size_t i = 0;
    for (auto c : s) {
      i = t.find(c, i);
      if (i == std::string::npos) {
        return false;
      }
      ++i;
    }
    return true;
  }
};
// @lc code=end
