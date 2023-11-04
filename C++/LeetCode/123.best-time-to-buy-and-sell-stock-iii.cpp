/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProfit(const std::vector<int>& prices) {
    constexpr size_t kTrans = 2;
    std::vector max_profits(kTrans + 1, 0);
    std::vector principals(kTrans + 1, -prices[0]);
    for (int i = 1; i < prices.size(); ++i) {
      for (int k = 1; k <= kTrans; ++k) {
        principals[k] = std::max(max_profits[k - 1] - prices[i], principals[k]);
        max_profits[k] = std::max(principals[k] + prices[i], max_profits[k]);
      }
    }
    return max_profits[kTrans];
  }
};
// @lc code=end
