/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string toHex(int num) {
    std::string result;
    auto x = static_cast<uint32_t>(num);
    while (x) {
      auto d = x & 0xF;
      result += d < 10 ? '0' + d : 'a' + d - 10;
      x >>= 4;
    }
    std::reverse(result.begin(), result.end());
    return result.size() ? result : "0";
  }
};
// @lc code=end
