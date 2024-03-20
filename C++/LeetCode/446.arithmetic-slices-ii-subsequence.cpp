/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(const std::vector<int>& nums) {
    int result = 0;
    std::vector<std::unordered_map<int64_t, int>> dp(nums.size());
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        auto diff = static_cast<int64_t>(nums[i]) - nums[j];
        auto it = dp[j].find(diff);
        auto count = it == dp[j].end() ? 0 : it->second;
        // Arithmetic sequences consist of at least 2 elements
        dp[i][diff] += count + 1;
        // Arithmetic sequences consist of at least 3 elements
        result += count;
      }
    }
    return result;
  }
};
// @lc code=end
