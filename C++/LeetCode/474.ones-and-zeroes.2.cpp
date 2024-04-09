/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int findMaxForm(const std::vector<std::string>& strs, int m, int n) {
    std::vector dp(m + 1, std::vector(n + 1, 0));
    for (const auto& s : strs) {
      int n0 = 0, n1 = 0;
      for (auto c : s) {
        if (c == '0') {
          ++n0;
        } else {
          ++n1;
        }
      }

      if (n0 > m && n1 > n) continue;
      for (int i = m; i >= n0; --i) {
        for (int j = n; j >= n1; --j) {
          dp[i][j] = std::max(dp[i - n0][j - n1] + 1, dp[i][j]);
        }
      }
    }
    return dp[m][n];
  }
};
// @lc code=end
