/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;
    result.reserve(matrix.size() * matrix[0].size());
    int row_min = 0, row_max = matrix.size() - 1;
    int col_min = 0, col_max = matrix[0].size() - 1;
    int i = 0, j = 0;
    while (true) {
      if (row_min++ > row_max) break;
      for (; j < col_max; ++j) {
        result.push_back(matrix[i][j]);
      }
      if (col_min > col_max--) break;
      for (; i < row_max; ++i) {
        result.push_back(matrix[i][j]);
      }
      if (row_min > row_max--) break;
      for (; j > col_min; --j) {
        result.push_back(matrix[i][j]);
      }
      if (col_min++ > col_max) break;
      for (; i > row_min; --i) {
        result.push_back(matrix[i][j]);
      }
    }
    result.push_back(matrix[i][j]);
    return result;
  }
};
// @lc code=end
