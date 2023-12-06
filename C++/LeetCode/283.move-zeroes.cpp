/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  void moveZeroes(std::vector<int>& nums) {
    auto it = nums.begin();
    for (auto num : nums) {
      if (num) {
        *it++ = num;
      }
    }
    std::fill(it, nums.end(), 0);
  }
};
// @lc code=end
