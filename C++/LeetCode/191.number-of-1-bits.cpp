/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    n = (n & 0x55555555) + ((n & 0xAAAAAAAA) >> 1);
    n = (n & 0x33333333) + ((n & 0xCCCCCCCC) >> 2);
    n = (n & 0x0F0F0F0F) + ((n & 0xF0F0F0F0) >> 4);
    n = (n & 0x00FF00FF) + ((n & 0xFF00FF00) >> 8);
    n = (n & 0x0000FFFF) + (n >> 16);
    return n;
  }
};
// @lc code=end
