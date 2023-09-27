/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> insert(
      std::vector<std::vector<int>>& intervals,
      std::vector<int>& new_interval) {
    std::vector<std::vector<int>> result;
    auto it = intervals.begin();
    for (; it < intervals.end() && (*it)[1] < new_interval[0]; ++it) {
      result.emplace_back(std::move(*it));
    }
    for (; it < intervals.end() && (*it)[0] <= new_interval[1]; ++it) {
      new_interval[0] = std::min((*it)[0], new_interval[0]);
      new_interval[1] = std::max((*it)[1], new_interval[1]);
    }
    result.emplace_back(std::move(new_interval));
    for (; it < intervals.end(); ++it) {
      result.emplace_back(std::move(*it));
    }
    return result;
  }
};
// @lc code=end
