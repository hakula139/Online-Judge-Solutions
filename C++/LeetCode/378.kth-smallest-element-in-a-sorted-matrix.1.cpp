/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  using Pair = std::pair<int, int>;

  int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
    auto m = matrix.size(), n = matrix[0].size();
    int result = 0;
    auto cmp = [&](const Pair& lhs, const Pair& rhs) {
      auto l_val = matrix[lhs.first][lhs.second];
      auto r_val = matrix[rhs.first][rhs.second];
      if (l_val > r_val) return true;
      if (l_val < r_val) return false;
      return lhs > rhs;
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> q{cmp};
    for (int i = 0; i < m; ++i) {
      q.emplace(i, 0);
    }
    while (k-- && q.size()) {
      auto [i, j] = q.top();
      q.pop();
      result = matrix[i][j];
      if (j + 1 < n) {
        q.emplace(i, j + 1);
      }
    }
    return result;
  }
};
// @lc code=end
