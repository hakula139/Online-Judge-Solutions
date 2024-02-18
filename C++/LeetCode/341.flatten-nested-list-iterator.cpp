/*
 * @lc app=leetcode id=341 lang=cpp
 *
 * [341] Flatten Nested List Iterator
 */

#include <stack>
#include <utility>
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation.
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer. The result is undefined if this NestedInteger holds a
  // nested list.
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list. The result is undefined if this NestedInteger holds a single integer.
  const std::vector<NestedInteger>& getList() const;
};

// @lc code=start
#include <cassert>

class NestedIterator {
 public:
  using It = std::vector<NestedInteger>::const_iterator;

  explicit NestedIterator(const std::vector<NestedInteger>& nested_list)
      : data_{nested_list} {
    stack_.emplace(data_.begin(), data_.end());
  }

  int next() {
    assert(hasNext());
    auto&& [it, end_it] = stack_.top();
    auto val = it->getInteger();
    ++it;
    return val;
  }

  bool hasNext() {
    while (stack_.size()) {
      auto&& [it, end_it] = stack_.top();
      if (it == end_it) {
        stack_.pop();
      } else if (it->isInteger()) {
        return true;
      } else {
        const auto& list = it->getList();
        ++it;
        stack_.emplace(list.begin(), list.end());
      }
    }
    return false;
  }

 private:
  std::vector<NestedInteger> data_;
  std::stack<std::pair<It, It>> stack_;
};
// @lc code=end
