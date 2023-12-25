/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int coinChange(std::vector<int>& coins, int amount) {
    std::sort(coins.begin(), coins.end());
    std::vector dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= amount - coins[0]; ++i) {
      if (dp[i] == INT_MAX) continue;
      for (auto coin : coins) {
        if (coin > amount - i) break;
        dp[i + coin] = std::min(dp[i] + 1, dp[i + coin]);
      }
    }
    return dp[amount] < INT_MAX ? dp[amount] : -1;
  }
};
// @lc code=end
