/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  int longestSubstring(const std::string& s, int k) {
    if (k == 1) return s.size();
    int max_len = 0;
    for (int u = 1; u <= kAlphabetSize && max_len < s.size(); ++u) {
      max_len = std::max(longestSubstring(s, k, u), max_len);
    }
    return max_len;
  }

 private:
  int longestSubstring(const std::string& s, int k, int target_unique) {
    std::vector<int> count(kAlphabetSize);
    int max_len = 0, begin = 0;
    int n_unique = 0, n_count_k = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto& count_end = ++count[s[i] - 'a'];
      if (count_end == 1) {
        ++n_unique;
      } else if (count_end == k) {
        ++n_count_k;
      }
      for (; n_unique > target_unique; ++begin) {
        auto& count_begin = --count[s[begin] - 'a'];
        if (count_begin == 0) {
          --n_unique;
        } else if (count_begin == k - 1) {
          --n_count_k;
        }
      }
      if (n_unique == n_count_k) {
        max_len = std::max(i - begin + 1, max_len);
      }
    }
    return max_len;
  }
};
// @lc code=end
