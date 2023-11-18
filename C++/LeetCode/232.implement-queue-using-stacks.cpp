/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
#include <stack>

class MyQueue {
 public:
  void push(int x) { si_.push(x); }

  int pop() {
    dump();
    auto x = so_.top();
    so_.pop();
    return x;
  }

  int peek() {
    dump();
    return so_.top();
  }

  bool empty() const { return so_.empty() && si_.empty(); }

 private:
  void dump() {
    if (so_.empty()) {
      while (si_.size()) {
        so_.push(si_.top());
        si_.pop();
      }
    }
  }

  std::stack<int> si_;
  std::stack<int> so_;
};
// @lc code=end
