/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int max_profit = 0, profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      profit += prices[i] - prices[i - 1];
      if (profit < 0) {
        profit = 0;
      } else if (profit > max_profit) {
        max_profit = profit;
      }
    }
    return max_profit;
  }
};
// @lc code=end
