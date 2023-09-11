/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <limits>

class Solution {
 public:
  int reverse(int x) {
    if (x == INT32_MIN) return 0;  // overflow
    if (x < 0) return -reverse(-x);

    int result = 0;
    for (; x > 0; x /= 10) {
      if ((INT32_MAX - x % 10) / 10 < result) {
        return 0;  // overflow
      }
      result = result * 10 + x % 10;
    }
    return result;
  }
};
// @lc code=end
