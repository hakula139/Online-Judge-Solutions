/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    if (nums.empty()) return;
    int i = nums.size() - 1;
    for (; i > 0; --i) {
      if (nums[i - 1] < nums[i]) {
        break;
      }
    }
    if (i > 0) {
      int j = i;
      for (; j < nums.size(); ++j) {
        if (nums[i - 1] >= nums[j]) {
          break;
        }
      }
      std::swap(nums[i - 1], nums[j - 1]);
    }
    std::reverse(nums.begin() + i, nums.end());
  }
};
// @lc code=end
