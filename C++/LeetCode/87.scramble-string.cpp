/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  bool isScramble(const std::string& s1, const std::string& s2) {
    auto n = s1.size();
    std::vector dp{n, std::vector{n, std::vector(n + 1, false)}};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j][1] = s1[i] == s2[j];
      }
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        for (int j = 0; j <= n - len; ++j) {
          for (int k = 1; k < len; ++k) {
            if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                (dp[i][j + len - k][k] && dp[i + k][j][len - k])) {
              dp[i][j][len] = true;
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};
// @lc code=end
