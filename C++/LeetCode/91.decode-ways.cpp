/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  int numDecodings(const std::string& s) {
    std::vector<int> dp(s.size() + 1);
    dp[0] = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '0') {
        dp[i + 1] += dp[i];
      }
      if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
        dp[i + 1] += dp[i - 1];
      }
    }
    return dp[s.size()];
  }
};
// @lc code=end
