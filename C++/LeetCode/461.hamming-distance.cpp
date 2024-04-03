/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
#include <bit>

class Solution {
 public:
  int hammingDistance(int x, int y) { return std::popcount<uint32_t>(x ^ y); }
};
// @lc code=end
