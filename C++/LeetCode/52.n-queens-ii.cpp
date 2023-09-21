/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  int totalNQueens(int n) {
    std::vector<std::pair<int, int>> board;
    return totalNQueens(board, 0, n);
  }

 private:
  int totalNQueens(std::vector<std::pair<int, int>>& board, int i, int n) {
    if (i == n) return 1;
    int result = 0;
    for (int j = 0; j < n; ++j) {
      if (isPosSafe(board, i, j)) {
        board.emplace_back(i, j);
        result += totalNQueens(board, i + 1, n);
        board.pop_back();
      }
    }
    return result;
  }

  bool isPosSafe(const std::vector<std::pair<int, int>>& board, int i, int j) {
    for (auto [bi, bj] : board) {
      if (bi == i || bj == j || bi - i == bj - j || bi - i == j - bj) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
