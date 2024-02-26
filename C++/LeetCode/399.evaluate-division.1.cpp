/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<double> calcEquation(
      const std::vector<std::vector<std::string>>& equations,
      const std::vector<double>& values,
      const std::vector<std::vector<std::string>>& queries) {
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        equation_map;
    for (int i = 0; i < equations.size(); ++i) {
      const auto& x = equations[i][0];
      const auto& y = equations[i][1];
      auto value = values[i];
      equation_map[x][y] = value;
      equation_map[x][x] = 1.0;
      equation_map[y][y] = 1.0;
      equation_map[y][x] = 1.0 / value;
    }

    // Floyd–Warshall algorithm
    for (auto&& [z, next_map] : equation_map) {
      for (const auto& [x, value_x] : next_map) {
        for (const auto& [y, value_y] : next_map) {
          if (x != y) {
            equation_map[x][y] = value_y / value_x;
          }
        }
      }
    }

    std::vector results(queries.size(), -1.0);
    for (int i = 0; i < queries.size(); ++i) {
      const auto& x = queries[i][0];
      const auto& y = queries[i][1];
      auto x_it = equation_map.find(x);
      if (x_it != equation_map.end()) {
        auto y_it = x_it->second.find(y);
        if (y_it != x_it->second.end()) {
          results[i] = y_it->second;
        }
      }
    }
    return results;
  }
};
// @lc code=end
