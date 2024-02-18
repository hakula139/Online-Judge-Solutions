/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */

#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation.
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  explicit NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer. The result is undefined if this NestedInteger holds a
  // nested list.
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger& ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list. The result is undefined if this NestedInteger holds a single integer.
  const std::vector<NestedInteger>& getList() const;
};

// @lc code=start
#include <algorithm>
#include <cctype>
#include <stack>
#include <string>

class Solution {
 public:
  NestedInteger deserialize(const std::string& s) {
    std::stack<NestedInteger> stack;
    stack.emplace();
    for (auto it = s.begin(); it < s.end();) {
      if (*it == '-' || ::isdigit(*it)) {
        auto end_it = std::find_if_not(it + 1, s.end(), ::isdigit);
        auto num = std::stoi(std::string{it, end_it});
        stack.top().add(NestedInteger{num});
        it = end_it;
        continue;
      }
      if (*it == '[') {
        stack.emplace();
      } else if (*it == ']') {
        NestedInteger ni = stack.top();
        stack.pop();
        stack.top().add(ni);
      }
      ++it;
    }
    return stack.top().getList().front();
  }
};
// @lc code=end
