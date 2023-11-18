/*
 * @lc app=leetcode id=223 lang=cpp
 *
 * [223] Rectangle Area
 */

// @lc code=start
#include <algorithm>

class Solution {
 public:
  int computeArea(int ax1, int ay1, int ax2, int ay2,  // 1st rectangle
                  int bx1, int by1, int bx2, int by2   // 2nd rectangle
  ) {
    auto x1 = std::max(ax1, bx1), y1 = std::max(ay1, by1);
    auto x2 = std::min(ax2, bx2), y2 = std::min(ay2, by2);
    return computeArea(ax1, ay1, ax2, ay2) + computeArea(bx1, by1, bx2, by2) -
           computeArea(x1, y1, x2, y2);
  }

 private:
  int computeArea(int x1, int y1, int x2, int y2) {
    return x1 < x2 && y1 < y2 ? (x2 - x1) * (y2 - y1) : 0;
  }
};
// @lc code=end
