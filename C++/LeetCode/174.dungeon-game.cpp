/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int calculateMinimumHP(const std::vector<std::vector<int>>& dungeon) {
    auto m = dungeon.size(), n = dungeon[0].size();
    std::vector dp(n + 1, INT_MAX);
    dp[n - 1] = 1;
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        dp[j] = std::max(std::min(dp[j], dp[j + 1]) - dungeon[i][j], 1);
      }
    }
    return dp[0];
  }
};
// @lc code=end
