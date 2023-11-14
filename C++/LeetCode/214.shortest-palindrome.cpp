/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string shortestPalindrome(const std::string& s) {
    auto tmp = s + '#';
    tmp.reserve(s.size() * 2 + 1);
    for (auto it = s.rbegin(); it < s.rend(); ++it) {
      tmp += *it;
    }

    std::vector<int> lps(tmp.size());
    for (int i = 1, j = 0; i < tmp.size(); ++i) {
      while (j > 0 && tmp[i] != tmp[j]) {
        j = lps[j - 1];
      }
      if (tmp[i] == tmp[j]) {
        lps[i] = ++j;
      }
    }

    auto result = tmp.substr(s.size() + 1, s.size() - lps.back());
    result += s;
    return result;
  }
};
// @lc code=end
