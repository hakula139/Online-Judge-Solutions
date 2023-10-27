/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
#include <cctype>
#include <string>

class Solution {
 public:
  bool isPalindrome(const std::string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (!std::isalnum(s[i])) {
        ++i;
      } else if (!std::isalnum(s[j])) {
        --j;
      } else if (std::tolower(s[i]) == std::tolower(s[j])) {
        ++i, --j;
      } else {
        break;
      }
    }
    return i >= j;
  }
};
// @lc code=end
