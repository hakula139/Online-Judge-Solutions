/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  using It = std::vector<int64_t>::iterator;

  int countRangeSum(const std::vector<int>& nums, int lower, int upper) {
    std::vector<int64_t> sum(nums.size() + 1);
    for (int i = 1; i <= nums.size(); ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }
    return mergeSort(sum.begin(), sum.end(), lower, upper);
  }

 private:
  int mergeSort(It begin_it, It end_it, int lower, int upper) {
    if (begin_it >= end_it - 1) return 0;
    auto mid_it = begin_it + (end_it - begin_it) / 2;
    auto count = mergeSort(begin_it, mid_it, lower, upper) +
                 mergeSort(mid_it, end_it, lower, upper);

    auto j = mid_it, k = mid_it;
    for (auto i = begin_it; i < mid_it; ++i) {
      j = std::lower_bound(j, end_it, *i + lower);
      k = std::upper_bound(k, end_it, *i + upper);
      count += k - j;
    }
    std::inplace_merge(begin_it, mid_it, end_it);
    return count;
  }
};
// @lc code=end
