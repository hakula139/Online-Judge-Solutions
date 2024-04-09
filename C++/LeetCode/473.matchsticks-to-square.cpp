/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
#include <map>
#include <numeric>
#include <vector>

class Solution {
 public:
  bool makesquare(const std::vector<int>& matchsticks) {
    auto sum = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum & 0x3) return false;
    sum >>= 2;

    std::map<int, int> match_map;
    for (auto len : matchsticks) {
      ++match_map[len];
    }
    return dfs(match_map, sum, 4);
  }

 private:
  bool dfs(std::map<int, int>& match_map, int sum, int n_side) {
    if (n_side <= 1) return true;
    auto it = match_map.rbegin();
    for (; it != match_map.rend() && !it->second; ++it) {
    }
    if (it == match_map.rend()) return false;
    auto& [len, count] = *it;
    if (len > sum) return false;
    --count;
    auto result = dfsSide(match_map, match_map.begin(), sum - len, sum, n_side);
    ++count;
    return result;
  }

  bool dfsSide(std::map<int, int>& match_map, std::map<int, int>::iterator it,
               int target, int sum, int n_side) {
    if (!target) {
      return dfs(match_map, sum, --n_side);
    }
    for (; it != match_map.end(); ++it) {
      auto& [len, count] = *it;
      if (!count) continue;
      if (len > target) break;
      --count;
      auto result = dfsSide(match_map, it, target - len, sum, n_side);
      ++count;
      if (result) return true;
    }
    return false;
  }
};
// @lc code=end
