/*
 * @lc app=leetcode id=477 lang=cpp
 *
 * [477] Total Hamming Distance
 */

// @lc code=start
#include <array>
#include <vector>

class Solution {
 public:
  int totalHammingDistance(const std::vector<int>& nums) {
    auto n = nums.size();
    std::array<int, 32> bit_count{};
    for (auto num : nums) {
      for (auto&& count : bit_count) {
        if (num & 0x1) {
          ++count;
        }
        num >>= 1;
      }
    }

    int result = 0;
    for (auto count : bit_count) {
      result += count * (n - count);
    }
    return result;
  }
};
// @lc code=end
