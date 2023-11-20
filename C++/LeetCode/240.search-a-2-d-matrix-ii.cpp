/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    auto m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] < target) {
        ++i;
      } else if (matrix[i][j] > target) {
        --j;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
