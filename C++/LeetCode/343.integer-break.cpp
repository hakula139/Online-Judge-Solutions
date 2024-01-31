/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start

class Solution {
 public:
  int integerBreak(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int result = 1;
    for (; n > 4; n -= 3) {
      result *= 3;
    }
    result *= n;
    return result;
  }
};
// @lc code=end
