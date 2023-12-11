/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <vector>

class NumArray {
 public:
  explicit NumArray(const std::vector<int>& nums) : sum_(nums.size() + 1) {
    for (int i = 1; i <= nums.size(); ++i) {
      sum_[i] = sum_[i - 1] + nums[i - 1];
    }
  }

  int sumRange(int left, int right) const {
    return sum_[right + 1] - sum_[left];
  }

 private:
  std::vector<int> sum_;
};
// @lc code=end
