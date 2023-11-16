/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum3(int k, int n) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    combination.reserve(k);
    bt(result, combination, 0, k, n);
    return result;
  }

 private:
  void bt(std::vector<std::vector<int>>& result, std::vector<int>& combination,
          int i, int k, int n) {
    if (n == 0 && k == 0) {
      result.push_back(combination);
      return;
    }

    int j_max = std::min(n, 10 - k);
    for (int j = i + 1; j <= j_max; ++j) {
      combination.push_back(j);
      bt(result, combination, j, k - 1, n - j);
      combination.pop_back();
    }
  }
};
// @lc code=end
