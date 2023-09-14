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
    std::vector<int> lps(needle.size());

    int j = 0;
    for (int i = 1; i < needle.size(); ++i) {
      while (j > 0 && needle[i] != needle[j]) {
        j = lps[j - 1];
      }
      if (needle[i] == needle[j]) {
        lps[i] = ++j;
      }
    }

    // KMP algorithm
    for (int i = 0, j = 0; i < haystack.size(); ++i) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = lps[j - 1];
      }
      if (haystack[i] == needle[j]) {
        if (j == needle.size() - 1) {
          return i - j;
        }
        ++j;
      }
    }
    return -1;
  }
};
// @lc code=end
