/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string licenseKeyFormatting(const std::string& s, int k) {
    std::string result;
    result.reserve(s.size());
    int len = 0;
    for (auto it = s.rbegin(); it < s.rend(); ++it) {
      if (!std::isalnum(*it)) continue;
      if (len == k) {
        result += '-';
        len = 0;
      }
      result += std::toupper(*it);
      ++len;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
