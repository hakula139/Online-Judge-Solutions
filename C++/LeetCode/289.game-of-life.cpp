/*
 * @lc app=leetcode id=289 lang=cpp
 *
 * [289] Game of Life
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  void gameOfLife(std::vector<std::vector<int>>& board) {
    auto m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        updateState(board, i, j);
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        board[i][j] >>= 1;
      }
    }
  }

 private:
  int getNumOfLiveNeighbors(
      const std::vector<std::vector<int>>& board, int i, int j) {
    int count = -board[i][j];
    for (int ni = i - 1; ni <= i + 1; ++ni) {
      for (int nj = j - 1; nj <= j + 1; ++nj) {
        if (isLive(board, ni, nj)) {
          ++count;
        }
      }
    }
    return count;
  }

  bool isLive(const std::vector<std::vector<int>>& board, int i, int j) {
    if (i < 0 || i >= board.size()) return false;
    if (j < 0 || j >= board[0].size()) return false;
    return board[i][j] & 0x1;
  }

  void updateState(std::vector<std::vector<int>>& board, int i, int j) {
    auto count = getNumOfLiveNeighbors(board, i, j);
    if ((board[i][j] && count == 2) || count == 3) {
      board[i][j] |= 0x2;
    }
  }
};
// @lc code=end
