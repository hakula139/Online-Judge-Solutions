/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
#include <string>

class Solution {
 public:
  int titleToNumber(const std::string& column_title) {
    int result = 0;
    for (auto c : column_title) {
      result = result * 26 - 'A' + c + 1;
    }
    return result;
  }
};
// @lc code=end
