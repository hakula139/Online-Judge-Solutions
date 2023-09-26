/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int minPathSum(const std::vector<std::vector<int>>& grid) {
    auto m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int>> dp{m + 1, std::vector<int>(n + 1, INT_MAX)};
    dp[m][n - 1] = 0;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] = std::min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
