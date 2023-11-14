/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, std::string& word) {
    auto m = board.size(), n = board[0].size(), d = word.size();
    if (m * n < d) return false;

    std::unordered_map<char, int> count;
    for (const auto& row : board) {
      for (auto c : row) {
        ++count[c];
      }
    }
    for (auto c : word) {
      if (--count[c] < 0) return false;
    }

    auto prefix_len = std::min(word.find_first_not_of(word.front()), d);
    auto suffix_len = d - std::min(word.find_last_not_of(word.back()), d);
    if (prefix_len > suffix_len) {
      std::reverse(word.begin(), word.end());
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dfs(board, i, j, word, 0)) return true;
      }
    }
    return false;
  }

 private:
  bool dfs(std::vector<std::vector<char>>& board, int i, int j,
           const std::string& word, int k) {
    if (i < 0 || i >= board.size()) return false;
    if (j < 0 || j >= board[0].size()) return false;
    if (board[i][j] == ' ') return false;
    if (board[i][j] != word[k]) return false;
    if (++k == word.size()) return true;

    auto saved_c = board[i][j];
    board[i][j] = ' ';
    if (dfs(board, i + 1, j, word, k)) return true;
    if (dfs(board, i, j + 1, word, k)) return true;
    if (dfs(board, i - 1, j, word, k)) return true;
    if (dfs(board, i, j - 1, word, k)) return true;
    board[i][j] = saved_c;
    return false;
  }
};
// @lc code=end
