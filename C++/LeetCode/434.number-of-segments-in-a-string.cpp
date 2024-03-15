/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  int countSegments(const std::string& s) {
    int result = 0;
    for (auto it = s.begin(); it < s.end();) {
      it = std::find_if_not(it, s.end(), ::isspace);
      if (it == s.end()) break;
      ++result;
      it = std::find(it, s.end(), ' ');
    }
    return result;
  }
};
// @lc code=end
