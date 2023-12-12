/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  bool isAdditiveNumber(const std::string& num) {
    auto n = num.size();
    if (n < 3) return false;
    int64_t num1 = 0;
    int len1 = num[0] == '0' ? 1 : (n - 1) / 2;
    for (int i = 1; i <= len1; ++i) {
      num1 = num1 * 10 + num[i - 1] - '0';
      int64_t num2 = 0;
      int len2 = num[i] == '0' ? 1 : std::min(n - i * 2, (n - i) / 2);
      for (int j = 1; j <= len2; ++j) {
        num2 = num2 * 10 + num[i + j - 1] - '0';
        if (judge(num, i + j, num1, num2)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool judge(const std::string& num, int i, int64_t num1, int64_t num2) {
    while (i < num.size()) {
      auto sum = num1 + num2;
      auto s = std::to_string(sum);
      if (num.substr(i, s.size()) != s) break;
      num1 = num2;
      num2 = sum;
      i += s.size();
    }
    return i == num.size();
  }
};
// @lc code=end
