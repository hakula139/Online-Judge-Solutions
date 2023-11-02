/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  int singleNumber(const std::vector<int>& nums) {
    return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
  }
};
// @lc code=end
