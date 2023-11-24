/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
#include <functional>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> singleNumber(const std::vector<int>& nums) {
    auto xor_res = std::accumulate(
        nums.begin(), nums.end(), 0U, std::bit_xor<int>());
    auto mask = xor_res & -xor_res;
    int result_1 = 0;
    for (auto num : nums) {
      if (num & mask) {
        result_1 ^= num;
      }
    }
    int result_2 = result_1 ^ xor_res;
    return {result_1, result_2};
  }
};
// @lc code=end
