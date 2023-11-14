/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
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

  std::vector<TrieNode*>& children() { return children_; }
  const std::vector<TrieNode*>& children() const { return children_; }
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

class WordDictionary {
 public:
  void addWord(const std::string& word) {
    auto node = &root_;
    for (auto c : word) {
      node = (*node)[c];
    }
    node->set_is_tail(true);
  }

  bool search(const std::string& word) const { return search(word, 0, &root_); }

 private:
  bool search(const std::string& word, int i, const TrieNode* node) const {
    for (; i < word.size(); ++i) {
      if (word[i] == '.') {
        for (const auto& child : node->children()) {
          if (child && search(word, i + 1, child)) {
            return true;
          }
        }
        return false;
      } else {
        const auto& child = node->at(word[i]);
        if (!child) return false;
        node = child;
      }
    }
    return node->is_tail();
  }

  TrieNode root_;
};
// @lc code=end
