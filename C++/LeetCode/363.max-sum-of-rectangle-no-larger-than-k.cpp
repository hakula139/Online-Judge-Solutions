/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
#include <algorithm>
#include <set>
#include <vector>

class Solution {
 public:
  int maxSumSubmatrix(const std::vector<std::vector<int>>& matrix, int k) {
    int result = INT_MIN;
    auto m = matrix.size(), n = matrix[0].size();
    for (int l = 0; l < m; ++l) {
      std::vector<int> col_sums(n);
      for (int r = l; r < m; ++r) {
        // Kadane's Algorithm
        int cur_sum = 0, max_sum = INT_MIN;
        for (int i = 0; i < n; ++i) {
          col_sums[i] += matrix[r][i];
          cur_sum = std::max(cur_sum + col_sums[i], col_sums[i]);
          max_sum = std::max(cur_sum, max_sum);
          if (max_sum == k) return k;
        }
        if (max_sum < k) {
          result = std::max(max_sum, result);
          continue;
        }

        std::set<int> sums{0};
        int sum = 0;
        for (auto col_sum : col_sums) {
          sum += col_sum;
          auto it = sums.lower_bound(sum - k);
          if (it != sums.end()) {
            result = std::max(sum - *it, result);
          }
          sums.insert(sum);
        }
      }
    }
    return result;
  }
};
// @lc code=end
