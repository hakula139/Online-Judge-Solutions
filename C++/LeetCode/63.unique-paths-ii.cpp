/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int uniquePathsWithObstacles(
      const std::vector<std::vector<int>>& obstacle_grid) {
    auto m = obstacle_grid.size(), n = obstacle_grid[0].size();
    std::vector<std::vector<int64_t>> dp{m + 1, std::vector<int64_t>(n + 1)};
    dp[m][n - 1] = 1;
    for (int i = m - 1; i >= 0; --i) {
      bool has_path = false;
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] = obstacle_grid[i][j] ? 0 : dp[i + 1][j] + dp[i][j + 1];
        has_path = has_path || dp[i][j];
      }
      if (!has_path) break;
    }
    return dp[0][0];
  }
};
// @lc code=end
