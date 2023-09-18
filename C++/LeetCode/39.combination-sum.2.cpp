/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> combinationSum(
      const std::vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> combinations;
    dfs(candidates, 0, target, result, combinations);
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
    if (target < 0) return;
    if (candidate_i >= candidates.size()) return;

    auto candidate = candidates[candidate_i];
    combinations.push_back(candidate);
    dfs(candidates, candidate_i, target - candidate, result, combinations);
    combinations.pop_back();
    dfs(candidates, candidate_i + 1, target, result, combinations);
  }
};
// @lc code=end
