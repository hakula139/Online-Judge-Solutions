/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    // A Finite State Machine with 3 states: buy, sell, cooldown.
    auto buy = -prices[0], sell = 0, cooldown = 0;
    for (auto price : prices) {
      auto prev_sell = sell;
      // After selling we must go to cooldown state, thus not possible to stay
      // at sell state.
      sell = buy + price;
      buy = std::max(buy, cooldown - price);
      cooldown = std::max(cooldown, prev_sell);
    }
    return std::max(sell, cooldown);
  }
};
// @lc code=end
