/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string convertToTitle(int column_number) {
    constexpr int kBase = 26;
    std::string result;
    while (column_number) {
      --column_number;
      result += 'A' + column_number % kBase;
      column_number /= kBase;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
