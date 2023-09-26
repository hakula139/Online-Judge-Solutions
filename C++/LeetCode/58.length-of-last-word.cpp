/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
#include <string>

class Solution {
 public:
  int lengthOfLastWord(const std::string& s) {
    int len = 0;
    for (auto it = s.rbegin(); it < s.rend(); ++it) {
      if (*it != ' ') {
        ++len;
      } else if (len > 0) {
        break;
      }
    }
    return len;
  }
};
// @lc code=end
