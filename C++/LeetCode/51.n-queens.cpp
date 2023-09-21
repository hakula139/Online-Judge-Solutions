/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> results;
    std::vector<std::pair<int, int>> board;
    solveNQueens(results, board, 0, n);
    return results;
  }

 private:
  void solveNQueens(std::vector<std::vector<std::string>>& results,
                    std::vector<std::pair<int, int>>& board, int i, int n) {
    if (i == n) {
      results.emplace_back(convertBoard(board, n));
      return;
    }
    for (int j = 0; j < n; ++j) {
      if (isPosSafe(board, i, j)) {
        board.emplace_back(i, j);
        solveNQueens(results, board, i + 1, n);
        board.pop_back();
      }
    }
  }

  bool isPosSafe(const std::vector<std::pair<int, int>>& board, int i, int j) {
    for (auto [bi, bj] : board) {
      if (bi == i || bj == j || bi - i == bj - j || bi - i == j - bj) {
        return false;
      }
    }
    return true;
  }

  std::vector<std::string> convertBoard(
      const std::vector<std::pair<int, int>>& board, size_t n) {
    std::vector<std::string> result{n, std::string(n, '.')};
    for (auto [i, j] : board) {
      result[i][j] = 'Q';
    }
    return result;
  }
};
// @lc code=end
