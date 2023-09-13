/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::unordered_set<std::string>> dp(n + 1);
    dp[1] = {"()"};
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        for (const auto& left : dp[j]) {
          for (const auto& right : dp[i - j]) {
            dp[i].insert(left + right);
          }
        }
        for (const auto& mid : dp[i - 1]) {
          dp[i].insert("(" + mid + ")");
        }
      }
    }
    return {dp[n].begin(), dp[n].end()};
  }
};
// @lc code=end
