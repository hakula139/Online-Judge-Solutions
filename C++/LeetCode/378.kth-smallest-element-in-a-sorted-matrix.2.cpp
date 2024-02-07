/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
    auto m = matrix.size(), n = matrix[0].size();
    int result = 0;
    auto begin = matrix[0][0], end = matrix[m - 1][n - 1];
    while (begin <= end) {
      auto mid = begin + (end - begin) / 2;
      if (countLessThanOrEqual(matrix, mid) >= k) {
        result = mid;
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
    }
    return result;
  }

 private:
  int countLessThanOrEqual(const std::vector<std::vector<int>>& matrix, int x) {
    int result = 0;
    int i = 0, j = matrix[0].size() - 1;
    for (; i < matrix.size(); ++i) {
      for (; j >= 0 && matrix[i][j] > x; --j) {
      }
      result += j + 1;
    }
    return result;
  }
};
// @lc code=end
