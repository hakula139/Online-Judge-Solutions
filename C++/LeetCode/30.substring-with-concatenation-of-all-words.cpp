/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> findSubstring(const std::string& s,
                                 const std::vector<std::string>& words) {
    auto word_len = words[0].size();
    auto window_len = word_len * words.size();
    if (s.size() < window_len) return {};

    std::vector<int> result;
    for (int offset = 0; offset < word_len; ++offset) {
      std::unordered_map<std::string, int> count;
      for (int i = 0; i < words.size(); ++i) {
        --count[words[i]];
      }

      for (int i = offset; i < s.size(); i += word_len) {
        auto word = s.substr(i, word_len);
        if (++count[word] == 0) {
          count.erase(word);
        }
        if (i >= window_len + offset) {
          auto prev_word = s.substr(i - window_len, word_len);
          if (--count[prev_word] == 0) {
            count.erase(prev_word);
          }
        }
        if (count.empty()) {
          result.push_back(i - window_len + word_len);
        }
      }
    }
    return result;
  }
};
// @lc code=end
