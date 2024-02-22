/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
#include <string>

class Solution {
 public:
  char findTheDifference(const std::string& s, const std::string& t) {
    auto result = t.back();
    for (int i = 0; i < s.size(); ++i) {
      result ^= s[i] ^ t[i];
    }
    return result;
  }
};
// @lc code=end
