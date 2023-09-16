/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool isValidSudoku(const std::vector<std::vector<char>>& board) {
    std::vector<std::vector<int>> row_count{9, std::vector<int>(9)};
    std::vector<std::vector<int>> col_count{9, std::vector<int>(9)};
    std::vector<std::vector<int>> box_count{9, std::vector<int>(9)};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        auto c = board[i][j];
        if (c == '.') continue;
        c -= '1';
        int k = i / 3 * 3 + j / 3;
        if (row_count[i][c]++ || col_count[j][c]++ || box_count[k][c]++) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
