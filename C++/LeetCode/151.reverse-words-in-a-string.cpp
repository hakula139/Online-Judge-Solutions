/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string reverseWords(std::string& s) {
    auto begin = s.begin(), end = s.begin();
    for (auto it = s.begin(); it < s.end(); ++it) {
      for (; it < s.end() && *it == ' '; ++it) {
      }
      if (it == s.end()) break;
      begin = it;
      for (; it < s.end() && *it != ' '; ++it) {
      }
      std::reverse(begin, it);
      if (end > s.begin()) {
        *end++ = ' ';
      }
      end = std::move(begin, it, end);
    }
    s.resize(end - s.begin());
    std::reverse(s.begin(), s.end());
    return s;
  }
};
// @lc code=end
