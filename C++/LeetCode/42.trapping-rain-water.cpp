/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int trap(const std::vector<int>& height) {
    int result = 0;
    int i = 0, j = height.size() - 1;
    int max_h_i = 0, max_h_j = 0;
    while (i <= j) {
      if (height[i] < height[j]) {
        if (height[i] < max_h_i) {
          result += max_h_i - height[i];
        } else {
          max_h_i = height[i];
        }
        ++i;
      } else {
        if (height[j] < max_h_j) {
          result += max_h_j - height[j];
        } else {
          max_h_j = height[j];
        }
        --j;
      }
    }
    return result;
  }
};
// @lc code=end
