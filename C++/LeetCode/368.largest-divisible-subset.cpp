/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::pair<int, int>> dp(nums.size(), {1, -1});
    int max_i = 0;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] % nums[j] == 0 && dp[j].first >= dp[i].first) {
          dp[i] = {dp[j].first + 1, j};
          if (dp[i].first > dp[max_i].first) {
            max_i = i;
          }
        }
      }
    }

    std::vector<int> result;
    for (int i = max_i; i >= 0; i = dp[i].second) {
      result.push_back(nums[i]);
    }
    return result;
  }
};
// @lc code=end
