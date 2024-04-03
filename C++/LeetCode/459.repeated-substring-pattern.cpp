/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool repeatedSubstringPattern(const std::string& s) {
    auto ss = s + s.substr(0, s.size() / 2);
    return ss.find(s, 1) != std::string::npos;
  }
};
// @lc code=end
