/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  int findNthDigit(int n) {
    int64_t i = 1, base = 1, n_max = 9;
    for (--n; n >= n_max;) {
      n -= n_max;
      ++i;
      base *= 10;
      n_max = 9 * i * base;
    }

    auto result = base + n / i;
    for (auto j = n % i + 1; j < i; ++j) {
      result /= 10;
    }
    return result % 10;
  }
};
// @lc code=end
