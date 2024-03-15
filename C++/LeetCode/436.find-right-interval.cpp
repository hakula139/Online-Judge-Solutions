/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> findRightInterval(
      const std::vector<std::vector<int>>& intervals) {
    auto n = intervals.size();
    std::vector indices(n, 0);
    for (int i = 0; i < n; ++i) {
      indices[i] = i;
    }
    std::sort(indices.begin(), indices.end(), [&](int lhs, int rhs) {
      return intervals[lhs][0] < intervals[rhs][0];
    });

    std::vector result(n, -1);
    for (auto it = indices.begin(); it < indices.end(); ++it) {
      auto right_it = std::lower_bound(
          it, indices.end(), intervals[*it][1],
          [&](int i, int target) { return intervals[i][0] < target; });
      if (right_it != indices.end()) {
        result[*it] = *right_it;
      }
    }
    return result;
  }
};
// @lc code=end
