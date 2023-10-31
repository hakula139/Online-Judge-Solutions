/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minCut(const std::string& s) {
    auto n = s.size();
    std::vector<int> dp(n + 1);
    for (int i = 0; i <= n; ++i) {
      dp[i] = i - 1;
    }
    auto expand = [&](int l, int r) {
      for (; l >= 0 && r < n && s[l] == s[r]; --l, ++r) {
        dp[r + 1] = std::min(dp[l] + 1, dp[r + 1]);
      }
    };
    for (int i = 0; i < n; ++i) {
      expand(i, i);
      expand(i, i + 1);
    }
    return dp[n];
  }
};
// @lc code=end
