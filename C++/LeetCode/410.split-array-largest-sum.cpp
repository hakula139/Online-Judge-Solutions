/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int splitArray(const std::vector<int>& nums, int k) {
    auto begin = *std::max_element(nums.begin(), nums.end());
    auto end = std::accumulate(nums.begin(), nums.end(), 0);
    while (begin < end) {
      auto mid = begin + (end - begin) / 2;
      auto sum = 0, i = 0, cur_k = 1;
      for (; i < nums.size(); ++i) {
        sum += nums[i];
        if (sum > mid) {
          sum = nums[i];
          if (++cur_k > k) break;
        }
      }
      if (cur_k <= k) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};
// @lc code=end
