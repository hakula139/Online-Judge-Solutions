/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int rob(const std::vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    return std::max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }

 private:
  int rob(const std::vector<int>& nums, int begin, int end) {
    auto cur = 0, prev = 0;
    for (int i = begin; i < end; ++i) {
      prev = std::max(cur, prev + nums[i]);
      std::swap(cur, prev);
    }
    return cur;
  }
};
// @lc code=end
