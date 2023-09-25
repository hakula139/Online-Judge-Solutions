/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> merge(
      std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> result;
    for (auto&& interval : intervals) {
      if (result.empty() || result.back().back() < interval.front()) {
        result.emplace_back(std::move(interval));
      } else if (interval.back() > result.back().back()) {
        result.back().back() = interval.back();
      }
    }
    return result;
  }
};
// @lc code=end
