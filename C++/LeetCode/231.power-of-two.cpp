/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
#include <bit>

class Solution {
 public:
  bool isPowerOfTwo(int n) {
    return n > 0 && std::popcount(static_cast<uint32_t>(n)) == 1;
  }
};
// @lc code=end
