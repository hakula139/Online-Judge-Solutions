/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum2(
      std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> combination;
    std::sort(candidates.begin(), candidates.end());
    bt(result, combination, candidates, 0, target);
    return result;
  }

 private:
  void bt(std::vector<std::vector<int>>& result, std::vector<int>& combination,
          const std::vector<int>& candidates, int i, int target) {
    if (target == 0) {
      result.emplace_back(combination);
      return;
    }

    for (int j = i; j < candidates.size(); ++j) {
      if (j > i && candidates[j] == candidates[j - 1]) continue;
      auto candidate = candidates[j];
      if (target < candidate) break;

      combination.push_back(candidate);
      bt(result, combination, candidates, j + 1, target - candidate);
      combination.pop_back();
    }
  }
};
// @lc code=end
