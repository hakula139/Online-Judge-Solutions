/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
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

class Trie {
 public:
  void insert(const std::string& word) {
    auto node = &root_;
    for (auto c : word) {
      node = (*node)[c];
    }
    node->set_is_tail(true);
  }

  bool search(const std::string& word, bool is_prefix = false) const {
    auto node = &root_;
    for (auto c : word) {
      const auto& child = node->at(c);
      if (!child) return false;
      node = child;
    }
    return is_prefix || node->is_tail();
  }

  bool startsWith(const std::string& prefix) const {
    return search(prefix, true);
  }

 private:
  TrieNode root_;
};
// @lc code=end
