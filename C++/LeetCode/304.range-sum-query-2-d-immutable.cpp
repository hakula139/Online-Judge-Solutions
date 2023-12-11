/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
#include <vector>

class NumMatrix {
 public:
  explicit NumMatrix(const std::vector<std::vector<int>>& matrix) {
    auto m = matrix.size(), n = matrix[0].size();
    sum_ = {m + 1, std::vector(n + 1, 0)};
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        sum_[i][j] = sum_[i - 1][j] + sum_[i][j - 1] - sum_[i - 1][j - 1] +
                     matrix[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) const {
    return sum_[row2 + 1][col2 + 1] - sum_[row2 + 1][col1] -
           sum_[row1][col2 + 1] + sum_[row1][col1];
  }

 private:
  std::vector<std::vector<int>> sum_;
};
// @lc code=end
