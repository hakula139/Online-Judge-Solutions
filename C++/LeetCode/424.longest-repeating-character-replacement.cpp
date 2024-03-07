/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  int characterReplacement(const std::string& s, int k) {
    int max_count = 0, begin = 0, end = 0;
    std::vector<int> count(kAlphabetSize);
    for (; end < s.size(); ++end) {
      max_count = std::max(++count[s[end] - 'A'], max_count);
      if (end - begin + 1 - max_count > k) {
        --count[s[begin++] - 'A'];
      }
    }
    return end - begin;
  }
};
// @lc code=end
