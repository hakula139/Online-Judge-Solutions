/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  int findSubstringInWraproundString(const std::string& s) {
    std::vector<int> max_lens(kAlphabetSize, 0);
    max_lens[s[0] - 'a'] = 1;
    for (int i = 1, len = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1] + 1 || s[i] == s[i - 1] - 25) {
        ++len;
      } else {
        len = 1;
      }
      auto& max_len = max_lens[s[i] - 'a'];
      max_len = std::max(len, max_len);
    }
    return std::accumulate(max_lens.begin(), max_lens.end(), 0);
  }
};
// @lc code=end
