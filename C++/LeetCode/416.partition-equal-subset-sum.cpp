/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bitset>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool canPartition(const std::vector<int>& nums) {
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) return false;
    std::bitset<10001> dp{1};
    for (auto num : nums) {
      dp |= dp << num;
    }
    return dp[sum / 2];
  }
};
// @lc code=end
