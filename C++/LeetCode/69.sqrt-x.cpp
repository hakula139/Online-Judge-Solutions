/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  int mySqrt(int x) {
    if (x == 0) return 0;
    int64_t result = x;
    while (result * result > x) {
      result = (result + x / result) / 2;
    }
    return result;
  }
};
// @lc code=end
