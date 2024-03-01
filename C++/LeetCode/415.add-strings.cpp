/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addStrings(const std::string& num1, const std::string& num2) {
    std::string result;
    int carry = 0;
    for (auto it1 = num1.rbegin(), it2 = num2.rbegin();
         it1 < num1.rend() || it2 < num2.rend() || carry;) {
      auto digit1 = it1 < num1.rend() ? (*it1++) - '0' : 0;
      auto digit2 = it2 < num2.rend() ? (*it2++) - '0' : 0;
      auto sum = digit1 + digit2 + carry;
      carry = sum / 10;
      sum %= 10;
      result += '0' + sum;
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
