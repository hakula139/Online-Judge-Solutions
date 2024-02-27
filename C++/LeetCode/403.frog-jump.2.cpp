/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool canCross(const std::vector<int>& stones) {
    auto n = stones.size();
    std::vector dp{n, std::vector(n + 1, false)};
    dp[0][1] = true;
    for (int j = 1; j < n; ++j) {
      for (int i = j - 1; i >= 0; --i) {
        auto step = stones[j] - stones[i];
        if (step > n) break;
        if (!dp[i][step]) continue;
        if (j == n - 1) return true;
        dp[j][step - 1] = true;
        dp[j][step] = true;
        dp[j][step + 1] = true;
      }
    }
    return false;
  }
};
// @lc code=end
