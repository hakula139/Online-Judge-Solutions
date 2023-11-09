/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int majorityElement(const std::vector<int>& nums) {
    int result = nums[0], count = 0;
    for (auto num : nums) {
      if (!count) {
        result = num;
        ++count;
      } else if (num == result) {
        ++count;
      } else {
        --count;
      }
    }
    return result;
  }
};
// @lc code=end
