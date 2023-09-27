/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    auto m = matrix.size(), n = matrix[0].size();
    int begin = 0, end = m * n;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      int i = mid / n, j = mid % n;
      if (target == matrix[i][j]) return true;
      if (target < matrix[i][j]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return false;
  }
};
// @lc code=end
