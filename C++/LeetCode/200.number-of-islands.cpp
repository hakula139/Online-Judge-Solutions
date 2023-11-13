/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int numIslands(std::vector<std::vector<char>>& grid) {
    auto m = grid.size(), n = grid[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j);
          ++result;
        }
      }
    }
    return result;
  }

 private:
  void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
    if (i < 0 || i >= grid.size()) return;
    if (j < 0 || j >= grid[0].size()) return;
    if (grid[i][j] != '1') return;
    grid[i][j] = ' ';

    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i, j - 1);
  }
};
// @lc code=end
