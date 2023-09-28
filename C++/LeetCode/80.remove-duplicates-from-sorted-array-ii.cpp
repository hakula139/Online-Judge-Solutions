/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    if (nums.size() <= 2) return nums.size();
    int i = 1;
    for (int j = 2; j < nums.size(); ++j) {
      if (nums[j] != nums[i - 1]) {
        nums[++i] = nums[j];
      }
    }
    return i + 1;
  }
};
// @lc code=end
