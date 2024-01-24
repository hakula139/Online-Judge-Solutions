/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    auto m = matrix.size(), n = matrix[0].size();
    mem_ = std::vector{m, std::vector(n, 0)};
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        result = std::max(result, dfs(matrix, i, j));
      }
    }
    return result;
  }

 private:
  int dfs(const std::vector<std::vector<int>>& matrix, int i, int j) {
    if (mem_[i][j] > 0) return mem_[i][j];
    mem_[i][j] = 1;
    if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
      mem_[i][j] = std::max(mem_[i][j], 1 + dfs(matrix, i - 1, j));
    }
    if (i < matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j]) {
      mem_[i][j] = std::max(mem_[i][j], 1 + dfs(matrix, i + 1, j));
    }
    if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
      mem_[i][j] = std::max(mem_[i][j], 1 + dfs(matrix, i, j - 1));
    }
    if (j < matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j]) {
      mem_[i][j] = std::max(mem_[i][j], 1 + dfs(matrix, i, j + 1));
    }
    return mem_[i][j];
  }

  std::vector<std::vector<int>> mem_;
};
// @lc code=end
