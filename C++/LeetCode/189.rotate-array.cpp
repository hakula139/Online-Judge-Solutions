/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  void rotate(std::vector<int>& nums, int k) {
    k %= nums.size();
    std::reverse(nums.begin(), nums.end() - k);
    std::reverse(nums.end() - k, nums.end());
    std::reverse(nums.begin(), nums.end());
  }
};
// @lc code=end
