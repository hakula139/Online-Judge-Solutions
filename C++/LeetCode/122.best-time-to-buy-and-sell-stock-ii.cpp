/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    int max_profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      auto profit = prices[i] - prices[i - 1];
      if (profit > 0) {
        max_profit += profit;
      }
    }
    return max_profit;
  }
};
// @lc code=end
