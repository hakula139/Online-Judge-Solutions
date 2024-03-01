/*
 * @lc app=leetcode id=407 lang=cpp
 *
 * [407] Trapping Rain Water II
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  using Pair = std::pair<int, int>;

  int trapRainWater(const std::vector<std::vector<int>>& height_map) {
    auto m = height_map.size(), n = height_map[0].size();
    if (m <= 2 || n <= 2) return 0;

    auto cmp = [&](const Pair& lhs, const Pair& rhs) {
      return height_map[lhs.first][lhs.second] >
             height_map[rhs.first][rhs.second];
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> q{cmp};
    std::vector visited{m, std::vector(n, false)};
    auto visit = [&](int i, int j) {
      q.emplace(i, j);
      visited[i][j] = true;
    };

    for (int i = 0; i < m; ++i) {
      visit(i, 0);
      visit(i, n - 1);
    }
    for (int j = 1; j < n - 1; ++j) {
      visit(0, j);
      visit(m - 1, j);
    }

    int result = 0, max_height = 0;
    const std::vector<Pair> directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while (q.size()) {
      auto [i0, j0] = q.top();
      q.pop();
      max_height = std::max(height_map[i0][j0], max_height);
      for (const auto& [di, dj] : directions) {
        auto i = i0 + di, j = j0 + dj;
        if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
          visit(i, j);
          result += std::max(max_height - height_map[i][j], 0);
        }
      }
    }
    return result;
  }
};
// @lc code=end
