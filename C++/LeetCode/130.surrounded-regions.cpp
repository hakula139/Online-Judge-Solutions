/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  void solve(std::vector<std::vector<char>>& board) {
    auto m = board.size(), n = board[0].size();
    std::vector visited{m, std::vector(n, false)};
    for (int i = 0; i < m; ++i) {
      dfs(board, visited, i, 0);
      dfs(board, visited, i, n - 1);
    }
    for (int j = 1; j < n - 1; ++j) {
      dfs(board, visited, 0, j);
      dfs(board, visited, m - 1, j);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!visited[i][j]) {
          board[i][j] = 'X';
        }
      }
    }
  }

 private:
  void dfs(std::vector<std::vector<char>>& board,
           std::vector<std::vector<bool>>& visited, int i, int j) {
    if (i < 0 || i >= board.size()) return;
    if (j < 0 || j >= board[0].size()) return;
    if (visited[i][j]) return;
    visited[i][j] = true;
    if (board[i][j] == 'X') return;

    dfs(board, visited, i + 1, j);
    dfs(board, visited, i, j + 1);
    dfs(board, visited, i - 1, j);
    dfs(board, visited, i, j - 1);
  }
};
// @lc code=end
