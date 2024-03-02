/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
#include <functional>
#include <vector>

enum Ocean : uint8_t {
  kPacific = 0b01,
  kAtlantic = 0b10,
  kAll = 0b11,
};

class Solution {
 public:
  std::vector<std::vector<int>> pacificAtlantic(
      const std::vector<std::vector<int>>& heights) {
    auto m = heights.size(), n = heights[0].size();
    std::vector can_flow{m, std::vector(n, 0U)};
    const std::vector dirs{1, 0, -1, 0, 1};

    std::function<void(int, int, Ocean)> dfs = [&](int i0, int j0, Ocean to) {
      if (can_flow[i0][j0] & to) return;
      can_flow[i0][j0] |= to;
      for (int k = 0; k < 4; ++k) {
        auto i = i0 + dirs[k], j = j0 + dirs[k + 1];
        if (i >= 0 && i < m && j >= 0 && j < n &&
            heights[i][j] >= heights[i0][j0]) {
          dfs(i, j, to);
        }
      }
    };

    for (int i = 0; i < m; ++i) {
      dfs(i, 0, kPacific);
      dfs(i, n - 1, kAtlantic);
    }
    for (int j = 0; j < n; ++j) {
      dfs(0, j, kPacific);
      dfs(m - 1, j, kAtlantic);
    }

    std::vector<std::vector<int>> result;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (can_flow[i][j] == kAll) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }
};
// @lc code=end
