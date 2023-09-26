/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    int row_min = 0, row_max = n - 1;
    int col_min = 0, col_max = n - 1;
    int i = 0, j = 0, val = 1;
    while (true) {
      if (row_min++ > row_max) break;
      for (; j < col_max; ++j) {
        matrix[i][j] = val++;
      }
      if (col_min > col_max--) break;
      for (; i < row_max; ++i) {
        matrix[i][j] = val++;
      }
      if (row_min > row_max--) break;
      for (; j > col_min; --j) {
        matrix[i][j] = val++;
      }
      if (col_min++ > col_max) break;
      for (; i > row_min; --i) {
        matrix[i][j] = val++;
      }
    }
    matrix[i][j] = val++;
    return matrix;
  }
};
// @lc code=end
