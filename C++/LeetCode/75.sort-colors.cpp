/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  void sortColors(std::vector<int>& nums) {
    int i0 = 0, i1 = 0, i2 = nums.size() - 1;
    while (i1 <= i2) {
      if (nums[i1] == 0) {
        std::swap(nums[i0++], nums[i1++]);
      } else if (nums[i1] == 1) {
        i1++;
      } else {
        std::swap(nums[i1], nums[i2--]);
      }
    }
  }
};
// @lc code=end
