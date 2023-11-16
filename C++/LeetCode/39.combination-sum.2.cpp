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
    std::vector<int> combination;
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
    if (target < 0) return;
    if (i >= candidates.size()) return;

    auto candidate = candidates[i];
    combination.push_back(candidate);
    bt(result, combination, candidates, i, target - candidate);
    combination.pop_back();
    bt(result, combination, candidates, i + 1, target);
  }
};
// @lc code=end
