/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  // x * (x + 1) / 2 <= n
  int arrangeCoins(int n) {
    return std::floor((std::sqrt((static_cast<int64_t>(n) << 3) + 1) - 1) / 2);
  }
};
// @lc code=end
