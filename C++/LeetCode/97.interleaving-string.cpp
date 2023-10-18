/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  bool isInterleave(
      const std::string& s1, const std::string& s2, const std::string& s3) {
    auto n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n1 + n2 != n3) return false;
    if (n1 < n2) return isInterleave(s2, s1, s3);
    if (!n2) return s1 == s3;

    std::vector<bool> dp(n2 + 1);
    dp[0] = true;
    for (int j = 1; j <= n2; ++j) {
      dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
    }
    for (int i = 1; i <= n1; ++i) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (int j = 1; j <= n2; ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }
    return dp[n2];
  }
};
// @lc code=end
