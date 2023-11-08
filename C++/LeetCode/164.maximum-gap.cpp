/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumGap(const std::vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;
    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
    int min = *min_it, max = *max_it;
    if (min == max) return 0;
    int gap = (max - min - 1) / (n - 1) + 1;

    std::vector<int> min_buckets(n, INT_MAX);
    std::vector<int> max_buckets(n, INT_MIN);
    for (auto num : nums) {
      auto i = (num - min) / gap;
      min_buckets[i] = std::min(num, min_buckets[i]);
      max_buckets[i] = std::max(num, max_buckets[i]);
    }

    int result = gap, prev_max = min;
    for (int i = 0; i < n; ++i) {
      if (min_buckets[i] != INT_MAX || max_buckets[i] != INT_MIN) {
        result = std::max(min_buckets[i] - prev_max, result);
        prev_max = max_buckets[i];
      }
    }
    return result;
  }
};
// @lc code=end
