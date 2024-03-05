/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
#include <bitset>
#include <unordered_set>
#include <vector>

class TrieNode {
 public:
  TrieNode() : children_(2) {}
  ~TrieNode() {
    for (auto child : children_) {
      delete child;
    }
  }

  void insert(int x) {
    std::bitset<32> bs(x);
    auto node = this;
    for (int i = 31; i >= 0; --i) {
      node = (*node)[bs[i]];
    }
  }

  int queryMaximumXOR(int x) {
    std::bitset<32> result;
    std::bitset<32> bs(x);
    auto node = this;
    for (int i = 31; node && i >= 0; --i) {
      if (node->at(!bs[i])) {
        result[i] = 1;
        node = node->at(!bs[i]);
      } else {
        node = node->at(bs[i]);
      }
    }
    return static_cast<int>(result.to_ulong());
  }

  TrieNode*& get(int i) { return children_.at(i); }
  TrieNode* const& at(int i) const { return children_.at(i); }
  TrieNode*& operator[](int i) {
    auto& child = get(i);
    if (!child) child = new TrieNode;
    return child;
  }

 private:
  std::vector<TrieNode*> children_;
};

class Solution {
 public:
  int findMaximumXOR(const std::vector<int>& nums) {
    int result = 0;
    TrieNode root;
    for (auto num : nums) {
      root.insert(num);
      result = std::max(root.queryMaximumXOR(num), result);
    }
    return result;
  }
};
// @lc code=end
