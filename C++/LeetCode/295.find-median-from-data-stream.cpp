/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <queue>

class MedianFinder {
 public:
  void addNum(int num) {
    if (high_.empty() || num >= high_.top()) {
      high_.push(num);
      if (high_.size() > low_.size() + 1) {
        low_.push(high_.top());
        high_.pop();
      }
    } else {
      low_.push(num);
      if (low_.size() > high_.size()) {
        high_.push(low_.top());
        low_.pop();
      }
    }
  }

  double findMedian() {
    if (high_.size() > low_.size()) {
      return high_.top();
    }
    return (high_.top() + low_.top()) / 2.0;
  }

 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> high_;
  std::priority_queue<int, std::vector<int>, std::less<int>> low_;
};
// @lc code=end
