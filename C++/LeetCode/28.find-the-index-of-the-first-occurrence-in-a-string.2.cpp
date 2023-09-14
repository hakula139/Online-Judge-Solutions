/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  int strStr(const std::string& haystack, const std::string& needle) {
    std::string s = needle + "#" + haystack;
    std::vector<int> lps(s.size());

    int j = 0;
    for (int i = 1; i < s.size(); ++i) {
      while (j > 0 && s[i] != s[j]) {
        j = lps[j - 1];
      }
      if (s[i] == s[j]) {
        lps[i] = ++j;
        if (j == needle.size()) {
          return i - 2 * needle.size();
        }
      }
    }
    return -1;
  }
};
// @lc code=end
