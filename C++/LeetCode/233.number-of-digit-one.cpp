/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
 public:
  int countDigitOne(int n) {
    int result = 0;
    for (auto exp = 1LL; exp <= n; exp *= 10) {
      int q = n / exp, r = n % exp;
      result += (q + 8) / 10 * exp + (q % 10 == 1) * (r + 1);
    }
    return result;
  }
};
// @lc code=end
