/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

class DisjointSet {
 public:
  using Entry = std::tuple<std::string, double, int>;

  Entry* find(const std::string& x, bool auto_create = true) {
    auto it = data_.find(x);
    if (it == data_.end()) {
      if (!auto_create) return nullptr;
      data_[x] = {x, 1.0, 0};
      return &data_[x];
    }

    auto& entry = it->second;
    auto& [parent, ratio, rank] = entry;
    if (parent != x) {
      auto parent_ratio = 1.0;
      std::tie(parent, parent_ratio, rank) = *find(parent);
      ratio *= parent_ratio;
    }
    return &entry;
  }

  // ratio = x / y
  void unionByRank(const std::string& x, const std::string& y, double ratio) {
    auto& [x0, x_ratio, x_rank] = *find(x);  // x_ratio = x / x0
    auto& [y0, y_ratio, y_rank] = *find(y);  // y_ratio = y / y0
    if (x0 == y0) return;  // x / y must have already been ratio.
    if (x_rank <= y_rank) {
      if (x_rank == y_rank) ++y_rank;
      // x0_ratio = x0 / y0 = y_ratio / x_ratio * ratio
      auto x0_ratio = y_ratio / x_ratio * ratio;
      data_[x0] = {y0, x0_ratio, y_rank};
    } else {
      // y0_ratio = y0 / x0 = x_ratio / y_ratio / ratio
      auto y0_ratio = x_ratio / y_ratio / ratio;
      data_[y0] = {x0, y0_ratio, x_rank};
    }
  }

  double query(const std::string& x, const std::string& y) {
    auto p_x_entry = find(x, false);
    if (!p_x_entry) return -1.0;
    auto p_y_entry = find(y, false);
    if (!p_y_entry) return -1.0;

    auto& [x0, x_ratio, x_rank] = *p_x_entry;  // x_ratio = x / x0
    auto& [y0, y_ratio, y_rank] = *p_y_entry;  // y_ratio = y / y0
    if (x0 != y0) return -1.0;  // There's no relation between x0 and y0.
    // ratio = x / y = x_ratio / y_ratio  (x0 == y0)
    return x_ratio / y_ratio;
  }

 private:
  std::unordered_map<std::string, Entry> data_;
};

class Solution {
 public:
  std::vector<double> calcEquation(
      const std::vector<std::vector<std::string>>& equations,
      const std::vector<double>& values,
      const std::vector<std::vector<std::string>>& queries) {
    DisjointSet disjoint_set;
    for (int i = 0; i < equations.size(); ++i) {
      const auto& x = equations[i][0];
      const auto& y = equations[i][1];
      auto value = values[i];
      disjoint_set.unionByRank(x, y, value);
    }

    std::vector results(queries.size(), -1.0);
    for (int i = 0; i < queries.size(); ++i) {
      const auto& x = queries[i][0];
      const auto& y = queries[i][1];
      results[i] = disjoint_set.query(x, y);
    }
    return results;
  }
};
// @lc code=end
