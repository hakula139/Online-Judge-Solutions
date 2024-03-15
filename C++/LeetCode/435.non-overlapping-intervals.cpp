/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });

    int result = 0;
    for (int i = 1, prev_i = 0; i < intervals.size(); ++i) {
      if (intervals[i][0] < intervals[prev_i][1]) {
        ++result;
      } else {
        prev_i = i;
      }
    }
    return result;
  }
};
// @lc code=end
