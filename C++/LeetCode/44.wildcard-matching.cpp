/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include <string>

class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    int i = 0, j = 0;
    int saved_i = -1, saved_j = -1;
    while (i < s.size()) {
      if (j < p.size() && p[j] == '*') {
        saved_i = i, saved_j = j++;
      } else if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
        ++i, ++j;
      } else if (saved_j >= 0) {
        i = ++saved_i, j = saved_j + 1;
      } else {
        break;
      }
    }
    if (i < s.size()) return false;
    for (; j < p.size() && p[j] == '*'; ++j) {
    }
    return j == p.size();
  }
};
// @lc code=end
