/*
 * @lc app=leetcode id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> findDuplicates(std::vector<int>& nums) {
    for (int i = 1; i <= nums.size(); ++i) {
      if (i == nums[i - 1]) continue;
      while (nums[i - 1] != nums[nums[i - 1] - 1]) {
        std::swap(nums[i - 1], nums[nums[i - 1] - 1]);
      }
    }

    std::vector<int> result;
    for (int i = 1; i <= nums.size(); ++i) {
      if (i != nums[i - 1]) {
        result.push_back(nums[i - 1]);
      }
    }
    return result;
  }
};
// @lc code=end
