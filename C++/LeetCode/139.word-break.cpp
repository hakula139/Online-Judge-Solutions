/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool wordBreak(const std::string& s,
                 const std::vector<std::string>& word_dict) {
    std::unordered_set<std::string> dict(word_dict.begin(), word_dict.end());
    std::set<int> word_lens;
    for (const auto& word : word_dict) {
      word_lens.insert(word.size());
    }

    std::vector<bool> dp(s.size() + 1);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (auto len : word_lens) {
        if (i < len) break;
        if (dp[i - len] && dict.contains(s.substr(i - len, len))) {
          dp[i] = true;
        }
      }
    }
    return dp[s.size()];
  }
};
// @lc code=end
