/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int countBattleships(const std::vector<std::vector<char>>& board) {
    auto m = board.size(), n = board[0].size();
    int result = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'X' && (i == 0 || board[i - 1][j] != 'X') &&
            (j == 0 || board[i][j - 1] != 'X')) {
          ++result;
        }
      }
    }
    return result;
  }
};
// @lc code=end
