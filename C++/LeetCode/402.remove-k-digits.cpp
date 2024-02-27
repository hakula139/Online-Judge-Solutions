/*
 * @lc app=leetcode id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
#include <string>

class Solution {
 public:
  std::string removeKdigits(const std::string& num, int k) {
    if (k <= 0) return num;
    if (k >= num.size()) return "0";

    std::string result;
    result.reserve(num.size() - k);
    for (auto digit : num) {
      while (k > 0 && result.size() && result.back() > digit) {
        result.pop_back();
        --k;
      }
      if (digit != '0' || result.size()) {  // skip leading zeros
        result += digit;
      }
    }
    while (k > 0 && result.size()) {
      result.pop_back();
      --k;
    }
    return result.size() ? result : "0";
  }
};
// @lc code=end
