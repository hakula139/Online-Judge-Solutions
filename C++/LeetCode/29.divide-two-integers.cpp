/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
#include <limits>

class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == INT32_MIN) {
      if (divisor == -1) return INT32_MAX;
      if (divisor < 0) return divide(INT32_MIN - divisor, divisor) + 1;
      return divide(INT32_MIN + divisor, divisor) - 1;
    }
    if (divisor == INT32_MIN) return 0;
    if (dividend < 0) return -divide(-dividend, divisor);
    if (divisor < 0) return -divide(dividend, -divisor);

    int result = 0, q = 1;
    for (; divisor <= dividend && divisor <= INT32_MAX >> 1;
         divisor <<= 1, q <<= 1) {
    }
    if (divisor > dividend) {
      divisor >>= 1, q >>= 1;
    }

    for (; q > 0; divisor >>= 1, q >>= 1) {
      while (divisor <= dividend) {
        dividend -= divisor;
        result += q;
      }
    }
    return result;
  }
};
// @lc code=end
