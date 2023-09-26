/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1));
    for (int i = m - 2; i >= 0; --i) {
      for (int j = n - 2; j >= 0; --j) {
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
