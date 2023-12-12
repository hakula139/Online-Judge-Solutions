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
      : nums_{nums}, sum_(nums_.size() + 1) {
    for (int i = 1; i <= nums.size(); ++i) {
      sum_[i] += nums[i - 1];
      int j = i + lsb(i);
      if (j <= nums.size()) {
        sum_[j] += sum_[i];
      }
    }
  }

  void update(int index, int val) {
    auto delta = val - nums_[index];
    if (delta == 0) return;
    nums_[index] = val;
    for (int i = index + 1; i <= nums_.size(); i += lsb(i)) {
      sum_[i] += delta;
    }
  }

  int sumRange(int left, int right) const { return sum(right + 1) - sum(left); }

 private:
  // Least Significant Bit
  int lsb(int x) const { return x & -x; }

  int sum(int i) const {
    int result = 0;
    for (; i > 0; i -= lsb(i)) {
      result += sum_[i];
    }
    return result;
  }

  std::vector<int> nums_;
  std::vector<int> sum_;  // Binary Indexed Tree (Fenwick Tree)
};
// @lc code=end
