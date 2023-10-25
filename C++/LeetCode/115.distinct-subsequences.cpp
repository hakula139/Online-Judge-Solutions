/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int numDistinct(const std::string& s, const std::string& t) {
    int m = s.size(), n = t.size();
    if (m < n) return 0;

    std::vector<int64_t> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i) {
      int j = std::max(1, n - m + i);
      auto prev = dp[j - 1];
      for (; j <= n; ++j) {
        auto cur = dp[j];
        if (s[i - 1] == t[j - 1]) {
          dp[j] += prev;
        }
        prev = cur;
      }
    }
    return dp[n];
  }
};
// @lc code=end
