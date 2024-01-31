/*
 * @lc app=leetcode id=336 lang=cpp
 *
 * [336] Palindrome Pairs
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

constexpr size_t kAlphabetSize = 26;
constexpr int kNull = -1;

template <class It>
bool isPalindrome(It begin_it, It end_it) {
  for (--end_it; begin_it < end_it; ++begin_it, --end_it) {
    if (*begin_it != *end_it) return false;
  }
  return true;
}

class TrieNode {
 public:
  TrieNode() : index_(kNull), children_(kAlphabetSize) {}
  ~TrieNode() {
    for (auto child : children_) {
      delete child;
    }
  }

  int index() const { return index_; }
  void set_index(int index) { index_ = index; }

  const std::vector<int>& palindromes() const { return palindromes_; }
  void add_palindrome(int index) { palindromes_.push_back(index); }

  TrieNode*& get(char c) { return children_.at(c - 'a'); }
  TrieNode* const& at(char c) const { return children_.at(c - 'a'); }
  TrieNode*& operator[](char c) {
    auto& child = get(c);
    if (!child) child = new TrieNode;
    return child;
  }

 private:
  int index_;
  std::vector<TrieNode*> children_;
  std::vector<int> palindromes_;
};

class Solution {
 public:
  std::vector<std::vector<int>> palindromePairs(
      const std::vector<std::string>& words) {
    TrieNode root;
    for (int i = 0; i < words.size(); ++i) {
      const auto& word = words[i];
      auto node = &root;
      if (isPalindrome(word.rbegin(), word.rend())) {
        node->add_palindrome(i);
      }
      for (auto it = word.rbegin(); it < word.rend(); ++it) {
        node = (*node)[*it];
        if (isPalindrome(it + 1, word.rend())) {
          node->add_palindrome(i);
        }
      }
      node->set_index(i);
    }

    std::vector<std::vector<int>> result;
    for (int i = 0; i < words.size(); ++i) {
      const auto& word = words[i];
      auto node = &root;
      for (auto it = word.begin(); node && it < word.end(); ++it) {
        auto j = node->index();
        if (j != kNull && i != j && isPalindrome(it, word.end())) {
          result.push_back({i, j});
        }
        node = node->at(*it);
      }

      if (!node) continue;
      for (auto j : node->palindromes()) {
        if (i != j) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }
};
// @lc code=end
