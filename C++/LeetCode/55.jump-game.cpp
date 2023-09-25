/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  bool canJump(const std::vector<int>& nums) {
    for (int i = 0, end = 0; i <= end; ++i) {
      end = std::max(i + nums[i], end);
      if (end >= nums.size() - 1) return true;
    }
    return false;
  }
};
// @lc code=end
