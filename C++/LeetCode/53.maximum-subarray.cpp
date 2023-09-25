/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxSubArray(const std::vector<int>& nums) {
    auto result = nums[0];
    auto sum = 0;
    for (auto num : nums) {
      sum += num;
      result = std::max(sum, result);
      if (sum < 0) {
        sum = 0;
      }
    }
    return result;
  }
};
// @lc code=end
