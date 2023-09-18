/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  int firstMissingPositive(std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] > 0 && nums[i] <= nums.size() &&
             nums[i] != nums[nums[i] - 1]) {
        std::swap(nums[i], nums[nums[i] - 1]);
      }
    }

    int i = 0;
    for (; i < nums.size() && nums[i] == i + 1; ++i) {
    }
    return i + 1;
  }
};
// @lc code=end
