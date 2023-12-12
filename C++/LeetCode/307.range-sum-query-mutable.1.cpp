/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include <vector>

class NumArray {
 public:
  explicit NumArray(const std::vector<int>& nums)
      : nums_{nums}, sum_(nums.size() * 4) {
    init(0, nums.size() - 1, 1);
  }

  void update(int index, int val) {
    update(index, val, 0, nums_.size() - 1, 1);
  }

  int sumRange(int left, int right) const {
    return sumRange(left, right, 0, nums_.size() - 1, 1);
  }

 private:
  void init(int begin, int end, int root) {
    if (begin == end) {
      sum_[root] = nums_[begin];
      return;
    }
    int mid = begin + (end - begin) / 2;
    int left = root * 2;
    int right = left + 1;
    init(begin, mid, left);
    init(mid + 1, end, right);
    sum_[root] = sum_[left] + sum_[right];
  }

  void update(int i, int val, int begin, int end, int root) {
    if (begin == end) {
      nums_[i] = val;
      sum_[root] = val;
      return;
    }
    int mid = begin + (end - begin) / 2;
    int left = root * 2;
    int right = left + 1;
    if (i <= mid) {
      update(i, val, begin, mid, left);
    } else {
      update(i, val, mid + 1, end, right);
    }
    sum_[root] = sum_[left] + sum_[right];
  }

  int sumRange(int left, int right, int begin, int end, int root) const {
    if (left <= begin && right >= end) {
      return sum_[root];
    }
    int mid = begin + (end - begin) / 2;
    int sum = 0;
    if (left <= mid) {
      sum += sumRange(left, right, begin, mid, root * 2);
    }
    if (right > mid) {
      sum += sumRange(left, right, mid + 1, end, root * 2 + 1);
    }
    return sum;
  }

  std::vector<int> nums_;
  std::vector<int> sum_;  // Segment Tree
};
// @lc code=end
