/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
#include <queue>

class MyStack {
 public:
  void push(int x) {
    q_.push(x);
    top_ = x;
  }

  int pop() {
    circulate();
    auto x = q_.front();
    q_.pop();
    return x;
  }

  int top() { return top_; }

  bool empty() const { return q_.empty(); }

 private:
  void circulate() {
    for (int i = q_.size() - 1; i > 0; --i) {
      top_ = q_.front();
      q_.push(top_);
      q_.pop();
    }
  }

  std::queue<int> q_;
  int top_ = 0;
};
// @lc code=end
