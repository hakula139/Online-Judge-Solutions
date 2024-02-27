/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
#include <algorithm>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
 public:
  bool canCross(const std::vector<int>& stones) {
    auto n = stones.size();
    std::vector<std::pair<std::unordered_set<int>, int>> dp(n);
    dp[0] = {{1}, 1};
    for (int i = 0; i < n; ++i) {
      auto& [steps_i, max_step_i] = dp[i];
      if (!max_step_i) continue;
      for (int j = i + 1; j < n; ++j) {
        auto& [steps_j, max_step_j] = dp[j];
        auto step = stones[j] - stones[i];
        if (steps_i.contains(step)) {
          if (j == n - 1) return true;
          steps_j.insert(step - 1);
          steps_j.insert(step);
          steps_j.insert(step + 1);
          max_step_j = std::max(step + 1, max_step_j);
        } else if (step > max_step_i) {
          break;
        }
      }
    }
    return false;
  }
};
// @lc code=end
