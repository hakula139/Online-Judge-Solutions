/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
#include <algorithm>
#include <set>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> getSkyline(
      const std::vector<std::vector<int>>& buildings) {
    std::vector<std::pair<int, int>> heights;
    for (const auto& b : buildings) {
      // By using negative value at starting points, insertion always comes
      // first when meeting the same x, so as to prevent gaps in cases like
      // [[1, 2, 5], [2, 3, 5]].
      heights.emplace_back(b[0], -b[2]);
      heights.emplace_back(b[1], b[2]);
    }
    std::sort(heights.begin(), heights.end());

    std::vector<std::vector<int>> result;
    std::multiset<int, std::greater<int>> q{0};
    int prev_h = 0;
    for (const auto& [x, h] : heights) {
      if (h < 0) {
        q.insert(-h);
      } else {
        q.extract(h);
      }
      auto cur_h = *q.begin();
      if (prev_h != cur_h) {
        result.push_back({x, cur_h});
        prev_h = cur_h;
      }
    }
    return result;
  }
};
// @lc code=end
