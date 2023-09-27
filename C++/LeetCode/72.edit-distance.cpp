/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int minDistance(const std::string& word1, const std::string& word2) {
    std::vector<std::vector<int>> dp{
        word1.size() + 1,
        std::vector<int>(word2.size() + 1),
    };
    for (int i = 0; i <= word1.size(); ++i) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= word2.size(); ++j) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] =
              std::min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
        }
      }
    }
    return dp[word1.size()][word2.size()];
  }
};
// @lc code=end
