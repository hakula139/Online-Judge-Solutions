/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    auto m = matrix.size(), n = matrix[0].size();
    auto clear_row = [&matrix, n](int row) {
      for (int j = 0; j < n; ++j) {
        matrix[row][j] = 0;
      }
    };
    auto clear_col = [&matrix, m](int col) {
      for (int i = 0; i < m; ++i) {
        matrix[i][col] = 0;
      }
    };

    bool should_clear_row_0 = false, should_clear_col_0 = false;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j]) continue;
        if (i) {
          matrix[i][0] = 0;
        } else {
          should_clear_row_0 = true;
        }
        if (j) {
          matrix[0][j] = 0;
        } else {
          should_clear_col_0 = true;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      if (!matrix[i][0]) clear_row(i);
    }
    for (int j = 1; j < n; ++j) {
      if (!matrix[0][j]) clear_col(j);
    }
    if (should_clear_row_0) clear_row(0);
    if (should_clear_col_0) clear_col(0);
  }
};
// @lc code=end
