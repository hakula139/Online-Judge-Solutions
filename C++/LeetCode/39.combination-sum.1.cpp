/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(
      const std::vector<int>& candidates, int target) {
    std::vector<std::vector<std::vector<int>>> dp(target + 1);
    dp[0] = {{}};
    for (auto num : candidates) {
      for (int i = num; i <= target; ++i) {
        for (auto combination : dp[i - num]) {
          combination.push_back(num);
          dp[i].emplace_back(combination);
        }
      }
    }
    return dp[target];
  }
};
// @lc code=end
