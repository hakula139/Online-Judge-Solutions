/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> getRow(int row_index) {
    std::vector<int> result{1};
    for (int i = 1; i <= row_index; ++i) {
      for (int j = 1, prev = 1; j < result.size(); ++j) {
        auto cur = result[j];
        result[j] += prev;
        prev = cur;
      }
      result.push_back(1);
    }
    return result;
  }
};
// @lc code=end
