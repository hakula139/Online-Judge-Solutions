/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int longestConsecutive(const std::vector<int>& nums) {
    std::unordered_set<int> nums_set(nums.begin(), nums.end());
    int result = 0;
    for (auto num : nums) {
      if (nums_set.contains(num - 1)) continue;
      int x = num + 1;
      while (nums_set.contains(x)) {
        ++x;
      }
      result = std::max(x - num, result);
    }
    return result;
  }
};
// @lc code=end
