/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
#include <utility>

class Solution {
 public:
  std::string longestPalindrome(const std::string& s) {
    if (s.size() <= 1) return s;

    auto expand = [&s](int begin, int end) -> std::pair<int, int> {
      for (; begin >= 1 && end < s.size() - 1 && s[begin - 1] == s[end + 1];
           --begin, ++end) {
      }
      return {begin, end};
    };

    std::pair result{0, 1};
    auto update_result = [&result](int begin, int end) {
      auto len = end - begin + 1;
      if (len > result.second) {
        result = {begin, len};
      }
    };

    for (int i = 0; i < s.size(); ++i) {
      std::apply(update_result, expand(i, i));
    }
    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        std::apply(update_result, expand(i, i + 1));
      }
    }

    return s.substr(result.first, result.second);
  }
};
// @lc code=end
