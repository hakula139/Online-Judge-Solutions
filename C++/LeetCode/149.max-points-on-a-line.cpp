/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <vector>

// slope = dy / dx, not directly using double for precision issues.
struct Slope {
  int dy = 0;
  int dx = 0;

  Slope(int dy, int dx) {
    if (dx == 0) {
      this->dy = 1, this->dx = 0;
    } else if (dy == 0) {
      this->dy = 0, this->dx = 0;
    } else {
      auto gcd = std::gcd(dy, dx);
      if (gcd) {
        dy /= gcd, dx /= gcd;
      }
      if (dx < 0) {
        dy = -dy, dx = -dx;
      }
      this->dy = dy, this->dx = dx;
    }
  }

  friend bool operator==(const Slope&, const Slope&);
};

bool operator==(const Slope& lhs, const Slope& rhs) {
  return lhs.dy == rhs.dy && lhs.dx == rhs.dx;
}

struct SlopeHash {
  size_t operator()(const Slope& slope) const {
    auto hash_dy = std::hash<int>{}(slope.dy);
    auto hash_dx = std::hash<int>{}(slope.dx);
    return hash_dy ^ (hash_dx << 1);
  }
};

class Solution {
 public:
  int maxPoints(const std::vector<std::vector<int>>& points) {
    auto n = points.size();
    if (n <= 2) return n;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      const auto& x = points[i];
      std::unordered_map<Slope, int, SlopeHash> slope_count;
      for (int j = i + 1; j < n; ++j) {
        const auto& y = points[j];
        Slope slope{y[1] - x[1], y[0] - x[0]};
        ++slope_count[slope];
      }
      for (const auto& [slope, count] : slope_count) {
        result = std::max(count + 1, result);
      }
    }
    return result;
  }
};
// @lc code=end
