/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class TrieNode {
 public:
  TrieNode() : is_tail_(false), children_(kAlphabetSize) {}
  ~TrieNode() {
    for (auto&& child : children_) {
      delete child;
    }
  }

  void insert(const std::string& word) {
    auto node = this;
    for (auto c : word) {
      node = (*node)[c];
    }
    node->set_is_tail(true);
  }

  bool is_tail() const { return is_tail_; }
  void set_is_tail(bool is_tail) { is_tail_ = is_tail; }

  TrieNode*& get(char c) { return children_.at(c - 'a'); }
  TrieNode* const& at(char c) const { return children_.at(c - 'a'); }
  TrieNode*& operator[](char c) {
    auto& child = get(c);
    if (!child) child = new TrieNode;
    return child;
  }

 private:
  bool is_tail_;
  std::vector<TrieNode*> children_;
};

class Solution {
 public:
  std::vector<std::string> findWords(
      std::vector<std::vector<char>>& board,
      const std::vector<std::string>& words) {
    auto m = board.size(), n = board[0].size();
    TrieNode root;
    for (const auto& word : words) {
      if (m * n < word.size()) continue;
      root.insert(word);
    }

    std::vector<std::string> result;
    std::string path;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dfs(board, i, j, result, path, &root);
      }
    }
    return result;
  }

 private:
  void dfs(std::vector<std::vector<char>>& board, int i, int j,
           std::vector<std::string>& result, std::string& path,
           TrieNode* node) {
    if (node->is_tail()) {
      result.push_back(path);
      node->set_is_tail(false);
    }

    if (i < 0 || i >= board.size()) return;
    if (j < 0 || j >= board[0].size()) return;
    auto c = board[i][j];
    if (c == ' ') return;
    auto child = node->at(c);
    if (!child) return;

    path += c;
    board[i][j] = ' ';
    dfs(board, i + 1, j, result, path, child);
    dfs(board, i, j + 1, result, path, child);
    dfs(board, i - 1, j, result, path, child);
    dfs(board, i, j - 1, result, path, child);
    board[i][j] = c;
    path.pop_back();
  }
};
// @lc code=end
