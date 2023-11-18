/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  int maximalSquare(const std::vector<std::vector<char>>& matrix) {
    auto m = matrix.size(), n = matrix[0].size();
    std::vector dp{2, std::vector(n + 1, 0)};
    int result = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (matrix[i - 1][j - 1] == '1') {
          dp[1][j] = std::min({dp[0][j - 1], dp[0][j], dp[1][j - 1]}) + 1;
          result = std::max(dp[1][j], result);
        } else {
          dp[1][j] = 0;
        }
      }
      std::swap(dp[0], dp[1]);
    }
    return result * result;
  }
};
// @lc code=end
