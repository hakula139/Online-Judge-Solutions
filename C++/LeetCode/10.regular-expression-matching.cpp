/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    std::vector<std::vector<bool>> dp{
        s.size() + 1,
        std::vector<bool>(p.size() + 1, false),
    };

    dp[s.size()][p.size()] = true;
    for (int i = s.size(); i >= 0; --i) {
      for (int j = p.size() - 1; j >= 0; --j) {
        bool is_match = i < s.size() && (p[j] == s[i] || p[j] == '.');
        if (j < p.size() - 1 && p[j + 1] == '*') {
          dp[i][j] = (is_match && dp[i + 1][j]) || dp[i][j + 2];
        } else {
          dp[i][j] = is_match && dp[i + 1][j + 1];
        }
      }
    }
    return dp[0][0];
  }
};
// @lc code=end
