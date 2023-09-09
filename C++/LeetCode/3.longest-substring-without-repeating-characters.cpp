/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string& s) {
    std::unordered_map<char, int> reverted_idx;
    int max_len = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      auto it = reverted_idx.find(s[j]);
      if (it == reverted_idx.end() || it->second < i) {
        int len = j - i + 1;
        max_len = len > max_len ? len : max_len;
      } else {
        i = it->second + 1;
      }
      reverted_idx[s[j]] = j;
    }
    return max_len;
  }
};
// @lc code=end
