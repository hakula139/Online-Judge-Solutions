/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int rob(const std::vector<int>& nums) {
    auto cur = 0, prev = 0;
    for (auto num : nums) {
      prev = std::max(cur, prev + num);
      std::swap(cur, prev);
    }
    return cur;
  }
};
// @lc code=end
