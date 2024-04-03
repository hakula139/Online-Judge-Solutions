/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int islandPerimeter(const std::vector<std::vector<int>>& grid) {
    auto m = grid.size(), n = grid[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!grid[i][j]) continue;
        if (i == m - 1 || !grid[i + 1][j]) ++result;
        if (j == n - 1 || !grid[i][j + 1]) ++result;
        if (i == 0 || !grid[i - 1][j]) ++result;
        if (j == 0 || !grid[i][j - 1]) ++result;
      }
    }
    return result;
  }
};
// @lc code=end
