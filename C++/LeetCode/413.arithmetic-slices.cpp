/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(const std::vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int result = 0, counter = 1, prev_delta = 0;
    for (int i = 1; i < nums.size(); ++i) {
      auto cur_delta = nums[i] - nums[i - 1];
      if (cur_delta == prev_delta) {
        ++counter;
        result += counter - 2;
      } else {
        counter = 2;
      }
      prev_delta = cur_delta;
    }
    return result;
  }
};
// @lc code=end
