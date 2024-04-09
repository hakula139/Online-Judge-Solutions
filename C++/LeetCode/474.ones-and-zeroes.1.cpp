/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  using Set = std::map<std::pair<int, int>, int>;
  using SetIt = Set::iterator;

  int findMaxForm(const std::vector<std::string>& strs, int m, int n) {
    Set set;
    for (const auto& s : strs) {
      ++set[compact(s)];
    }
    return bt(0, set, set.begin(), m, n);
  }

 private:
  int bt(int count, Set& set, SetIt it, int m, int n) {
    auto result = count;
    for (; it != set.end(); ++it) {
      auto& [pair, k] = *it;
      auto [n0, n1] = pair;
      if (n0 > m && n1 > n) break;
      if (n0 <= m && n1 <= n) {
        auto next_it = --k ? it : std::next(it);
        auto sub_result = bt(count + 1, set, next_it, m - n0, n - n1);
        result = std::max(sub_result, result);
        ++k;
      }
    }
    return result;
  }

  std::pair<int, int> compact(const std::string& s) {
    int n0 = 0, n1 = 0;
    for (auto c : s) {
      if (c == '0') {
        ++n0;
      } else {
        ++n1;
      }
    }
    return {n0, n1};
  }
};
// @lc code=end
