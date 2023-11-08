/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <utility>

class MinStack {
 public:
  void push(int val) {
    auto min_val = stack_.size() ? std::min(val, stack_.top().second) : val;
    stack_.emplace(val, min_val);
  }

  void pop() { stack_.pop(); }

  int top() const { return stack_.top().first; }

  int getMin() { return stack_.top().second; }

 private:
  std::stack<std::pair<int, int>> stack_;
};
// @lc code=end
