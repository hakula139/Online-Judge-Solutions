/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combine(int n, int k) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    combination.reserve(k);
    combine(1, n, k, combination, result);
    return result;
  }

 private:
  void combine(int i, int n, int k, std::vector<int>& combination,
               std::vector<std::vector<int>>& result) {
    if (!k) {
      result.push_back(combination);
      return;
    }
    for (int j = i; j <= n; ++j) {
      combination.push_back(j);
      combine(j + 1, n, k - 1, combination, result);
      combination.pop_back();
    }
  }
};
// @lc code=end
