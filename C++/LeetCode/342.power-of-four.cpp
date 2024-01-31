/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
#include <bit>

class Solution {
 public:
  bool isPowerOfFour(int n) {
    return n > 0 && !(n & (n - 1)) && (n & 0x55555555);
  }
};
// @lc code=end
