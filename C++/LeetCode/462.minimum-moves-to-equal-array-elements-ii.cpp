/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
 public:
  int minMoves2(std::vector<int>& nums) {
    auto mid_it = nums.begin() + nums.size() / 2;
    std::nth_element(nums.begin(), mid_it, nums.end());
    auto end_num = *mid_it;
    int result = 0;
    for (auto num : nums) {
      result += std::abs(num - end_num);
    }
    return result;
  }
};
// @lc code=end
