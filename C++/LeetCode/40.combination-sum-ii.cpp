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
      const std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> combinations;
    auto sorted_candidates = candidates;
    std::sort(sorted_candidates.begin(), sorted_candidates.end());
    dfs(sorted_candidates, 0, target, result, combinations);
    return result;
  }

 private:
  void dfs(const std::vector<int>& candidates, int candidate_i, int target,
           std::vector<std::vector<int>>& result,
           std::vector<int>& combinations) {
    if (target == 0) {
      result.emplace_back(combinations);
      return;
    }

    for (int i = candidate_i; i < candidates.size(); ++i) {
      if (i > candidate_i && candidates[i] == candidates[i - 1]) continue;
      auto candidate = candidates[i];
      if (target < candidate) break;

      combinations.push_back(candidate);
      dfs(candidates, i + 1, target - candidate, result, combinations);
      combinations.pop_back();
    }
  }
};
// @lc code=end
