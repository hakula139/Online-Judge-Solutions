/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(int num_rows) {
    std::vector<std::vector<int>> result{{1}};
    for (int i = 2; i <= num_rows; ++i) {
      const auto& prev = result.back();
      std::vector<int> row(i, 1);
      for (int j = 1; j < row.size() - 1; ++j) {
        row[j] = prev[j - 1] + prev[j];
      }
      result.emplace_back(std::move(row));
    }
    return result;
  }
};
// @lc code=end
