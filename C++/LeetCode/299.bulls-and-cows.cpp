/*
 * @lc app=leetcode id=299 lang=cpp
 *
 * [299] Bulls and Cows
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string getHint(const std::string& secret, const std::string& guess) {
    int n_bulls = 0, n_cows = 0;
    std::unordered_map<char, int> s_count, g_count;
    for (int i = 0; i < guess.size(); ++i) {
      if (secret[i] == guess[i]) {
        ++n_bulls;
      } else {
        ++s_count[secret[i]];
        ++g_count[guess[i]];
      }
    }
    for (const auto& [c, v] : s_count) {
      n_cows += std::min(v, g_count[c]);
    }
    return std::to_string(n_bulls) + 'A' + std::to_string(n_cows) + 'B';
  }
};
// @lc code=end
