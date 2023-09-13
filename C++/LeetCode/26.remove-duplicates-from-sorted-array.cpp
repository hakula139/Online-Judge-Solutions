/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int i = 0;
    for (int j = 1; j < nums.size(); ++j) {
      if (nums[j] != nums[i]) {
        nums[++i] = nums[j];
      }
    }
    return i + 1;
  }
};
// @lc code=end
