/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  using Rect = std::vector<int>;

  bool isRectangleCover(const std::vector<Rect>& rects) {
    // The number of occurrance of each corner must be even, except the four
    // corners of the final rectangle region formed.
    std::unordered_set<uint64_t> corners;
    size_t total_area = 0;
    Rect wrapper{INT_MAX, INT_MAX, INT_MIN, INT_MIN};

    auto add_corner = [&](int x, int y) {
      auto hash = (static_cast<uint64_t>(x) << 32) | static_cast<uint32_t>(y);
      auto [it, inserted] = corners.insert(hash);
      if (!inserted) corners.erase(it);
    };

    auto add_rect = [&](const Rect& rect) {
      add_corner(rect[0], rect[1]);
      add_corner(rect[0], rect[3]);
      add_corner(rect[2], rect[1]);
      add_corner(rect[2], rect[3]);
    };

    for (const auto& rect : rects) {
      add_rect(rect);
      total_area += getArea(rect);
      wrapper[0] = std::min(rect[0], wrapper[0]);
      wrapper[1] = std::min(rect[1], wrapper[1]);
      wrapper[2] = std::max(rect[2], wrapper[2]);
      wrapper[3] = std::max(rect[3], wrapper[3]);
    }

    if (corners.size() != 4) return false;
    add_rect(wrapper);
    return corners.empty() && total_area == getArea(wrapper);
  }

 private:
  size_t getArea(const Rect& rect) {
    return static_cast<size_t>(rect[2] - rect[0]) * (rect[3] - rect[1]);
  }
};
// @lc code=end
