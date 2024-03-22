/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int findMinArrowShots(std::vector<std::vector<int>>& points) {
    std::sort(
        points.begin(), points.end(), [](const auto& lhs, const auto& rhs) {
          if (lhs[1] < rhs[1]) return true;
          if (lhs[1] > rhs[1]) return false;
          return lhs[0] < rhs[0];
        });

    int result = 0;
    for (auto it = points.begin(); it < points.end(); ++result) {
      auto end = (*it)[1];
      it = std::find_if(it + 1, points.end(), [end](const auto& point) {
        return point[0] > end;
      });
    }
    return result;
  }
};
// @lc code=end
