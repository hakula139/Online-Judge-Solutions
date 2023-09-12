/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxArea(const std::vector<int>& height) {
    int i = 0, j = height.size() - 1;
    int max_area = 0;
    while (i < j) {
      int area = std::min(height[i], height[j]) * (j - i);
      max_area = std::max(area, max_area);
      height[i] < height[j] ? ++i : --j;
    }
    return max_area;
  }
};
// @lc code=end
