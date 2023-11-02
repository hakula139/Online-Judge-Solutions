/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> wordBreak(
      const std::string& s, const std::vector<std::string>& word_dict) {
    std::unordered_set<std::string> dict(word_dict.begin(), word_dict.end());
    std::set<int> word_lens;
    for (const auto& word : word_dict) {
      word_lens.insert(word.size());
    }

    std::vector<std::vector<std::string>> dp(s.size() + 1);
    dp[0].emplace_back("");
    for (int i = 1; i <= s.size(); ++i) {
      for (auto len : word_lens) {
        int j = i - len;
        if (j < 0) break;
        if (dp[j].empty()) continue;
        auto word = s.substr(j, len);
        if (dict.contains(word)) {
          if (j > 0) word = ' ' + word;
          for (const auto& prefix : dp[j]) {
            dp[i].emplace_back(prefix + word);
          }
        }
      }
    }
    return dp[s.size()];
  }
};
// @lc code=end
