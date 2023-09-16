/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
#include <unordered_set>
#include <vector>

class Solution {
 public:
  using Matrix = std::vector<std::vector<char>>;
  using GuessMatrix = std::vector<std::vector<std::unordered_set<char>>>;

  void solveSudoku(Matrix& board) {
    GuessMatrix guess{9, {9, {'1', '2', '3', '4', '5', '6', '7', '8', '9'}}};
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        insertSudoku(guess, i, j, board[i][j]);
      }
    }
    guessSudoku(guess);
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        board[i][j] = *guess[i][j].begin();
      }
    }
  }

 private:
  bool insertSudoku(GuessMatrix& guess, int i, int j, char digit) {
    if (digit == '.') return true;
    guess[i][j] = {digit};
    int ki_base = i / 3 * 3, kj_base = j / 3 * 3;
    for (int n = 0; n < 9; ++n) {
      if (n != j && !eraseSudoku(guess, i, n, digit)) return false;
      if (n != i && !eraseSudoku(guess, n, j, digit)) return false;
      int ki = ki_base + n / 3, kj = kj_base + n % 3;
      if (ki != i && kj != j && !eraseSudoku(guess, ki, kj, digit)) {
        return false;
      }
    }
    return true;
  }

  bool eraseSudoku(GuessMatrix& guess, int i, int j, char digit) {
    auto& digits = guess[i][j];
    if (digits.erase(digit) && digits.size() == 1) {
      if (!insertSudoku(guess, i, j, *digits.begin())) return false;
    }
    return !digits.empty();
  }

  bool guessSudoku(GuessMatrix& guess) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (guess[i][j].empty()) return false;
        if (guess[i][j].size() == 1) continue;

        auto cur_state = guess;
        auto digits = guess[i][j];
        for (auto c : digits) {
          if (insertSudoku(guess, i, j, c) && guessSudoku(guess)) {
            return true;
          }
          guess = cur_state;
        }
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
