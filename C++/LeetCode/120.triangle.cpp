/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int minimumTotal(const std::vector<std::vector<int>>& triangle) {
    auto dp = triangle.back();
    for (int i = dp.size() - 2; i >= 0; --i) {
      for (int j = 0; j <= i; ++j) {
        dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
      }
    }
    return dp[0];
  }
};
// @lc code=end
