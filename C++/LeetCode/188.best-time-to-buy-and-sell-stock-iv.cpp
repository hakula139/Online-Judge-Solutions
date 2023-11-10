/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProfit(int k, const std::vector<int>& prices) {
    std::vector max_profits(k + 1, 0);
    std::vector principals(k + 1, -prices[0]);
    for (int i = 1; i < prices.size(); ++i) {
      for (int j = 1; j <= k; ++j) {
        principals[j] = std::max(max_profits[j - 1] - prices[i], principals[j]);
        max_profits[j] = std::max(principals[j] + prices[i], max_profits[j]);
      }
    }
    return max_profits[k];
  }
};
// @lc code=end
