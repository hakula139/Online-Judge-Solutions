/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  // (i, j) -> (j, i) -> (j, n - i - 1)
  void rotate(std::vector<std::vector<int>>& matrix) {
    auto n = matrix.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        std::swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < n / 2; ++i) {
        std::swap(matrix[j][i], matrix[j][n - i - 1]);
      }
    }
  }
};
// @lc code=end
