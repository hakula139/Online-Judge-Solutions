/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int minMoves(const std::vector<int>& nums) {
    int result = 0;
    auto min = *std::min_element(nums.begin(), nums.end());
    for (auto num : nums) {
      result += num - min;
    }
    return result;
  }
};
// @lc code=end
