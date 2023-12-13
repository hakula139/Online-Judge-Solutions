/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> findMinHeightTrees(
      int n, const std::vector<std::vector<int>>& edges) {
    if (n == 1) return {0};

    std::vector<std::vector<int>> graph(n);
    std::vector<int> degrees(n);
    auto insert_edge = [&](int x, int y) {
      graph[x].push_back(y);
      ++degrees[x];
    };
    for (const auto& edge : edges) {
      insert_edge(edge[0], edge[1]);
      insert_edge(edge[1], edge[0]);
    }

    std::vector<int> level;
    for (int i = 0; i < n; ++i) {
      if (degrees[i] == 1) {
        level.push_back(i);
      }
    }
    while (true) {
      std::vector<int> next_level;
      for (auto x : level) {
        for (auto y : graph[x]) {
          if (--degrees[y] == 1) {
            next_level.push_back(y);
          }
        }
      }
      if (next_level.empty()) break;
      std::swap(level, next_level);
    }
    return level;
  }
};
// @lc code=end
