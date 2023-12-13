/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxCoins(const std::vector<int>& nums) {
    std::vector<int> b{1};
    b.reserve(nums.size() + 2);
    for (auto num : nums) {
      // 0's are ignored since they don't provide coins.
      if (num) b.push_back(num);
    }
    b.push_back(1);

    auto n = b.size();
    // dp[i][j] = max coins collected by bursting the balloons from range
    // (i, j) (EXCLUSIVE, which is equivalent to [i + 1, j - 1]).
    std::vector dp{n, std::vector(n, 0)};
    for (int k = 2; k < n; ++k) {
      for (int i = 0; i < n - k; ++i) {
        int j = i + k;
        for (int m = i + 1; m < j; ++m) {
          // m is the LAST balloon to burst, after bursting (i, m) and (m, j).
          // Therefore, here we have m adjacent to i and j.
          auto coins = dp[i][m] + b[i] * b[m] * b[j] + dp[m][j];
          dp[i][j] = std::max(coins, dp[i][j]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end
