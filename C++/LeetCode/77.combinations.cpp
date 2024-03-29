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
    bt(result, combination, 1, n, k);
    return result;
  }

 private:
  void bt(std::vector<std::vector<int>>& result, std::vector<int>& combination,
          int i, int n, int k) {
    if (!k) {
      result.push_back(combination);
      return;
    }
    for (int j = i; j <= n; ++j) {
      combination.push_back(j);
      bt(result, combination, j + 1, n, k - 1);
      combination.pop_back();
    }
  }
};
// @lc code=end
