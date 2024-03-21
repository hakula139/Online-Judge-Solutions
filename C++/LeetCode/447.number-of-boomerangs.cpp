/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  using Point = std::vector<int>;

  int numberOfBoomerangs(const std::vector<Point>& points) {
    auto n = points.size();
    int result = 0;
    std::vector<std::unordered_map<int, int>> distance_map(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        auto distance = getDistance(points[i], points[j]);
        result += (distance_map[i][distance]++) << 1;
        result += (distance_map[j][distance]++) << 1;
      }
    }
    return result;
  }

 private:
  int getDistance(const Point& p1, const Point& p2) {
    auto dx = p1[0] - p2[0], dy = p1[1] - p2[1];
    return dx * dx + dy * dy;
  }
};
// @lc code=end
