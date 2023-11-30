/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int nthUglyNumber(int n) {
    std::vector<int> dp(n, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    for (int i = 1; i < n; ++i) {
      dp[i] = std::min({2 * dp[i2], 3 * dp[i3], 5 * dp[i5]});
      if (dp[i] == 2 * dp[i2]) ++i2;
      if (dp[i] == 3 * dp[i3]) ++i3;
      if (dp[i] == 5 * dp[i5]) ++i5;
    }
    return dp[n - 1];
  }
};
// @lc code=end
