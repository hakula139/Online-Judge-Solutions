/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start

class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int sum = 10, cur = 9;
    for (int i = 2; i <= n; ++i) {
      cur *= 11 - i;
      sum += cur;
    }
    return sum;
  }
};
// @lc code=end
