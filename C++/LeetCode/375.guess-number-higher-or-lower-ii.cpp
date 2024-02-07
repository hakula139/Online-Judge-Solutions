/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int getMoneyAmount(int n) {
    if (n == 1) return 0;
    std::vector dp(n + 1, std::vector(n + 1, INT_MAX));
    for (int i = 1; i <= n; ++i) {
      dp[i][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      dp[i][i + 1] = i;
    }
    for (int len = 2; len < n; ++len) {
      for (int i = 1; i <= n - len; ++i) {
        int j = i + len;
        for (int m = i + 1; m < j; ++m) {
          auto sum = m + std::max(dp[i][m - 1], dp[m + 1][j]);
          dp[i][j] = std::min(sum, dp[i][j]);
        }
      }
    }
    return dp[1][n];
  }
};
// @lc code=end
