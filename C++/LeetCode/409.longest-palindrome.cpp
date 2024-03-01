/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  int longestPalindrome(const std::string& s) {
    std::unordered_map<char, int> count;
    for (auto c : s) {
      ++count[c];
    }
    int result = 0, offset = 0;
    for (const auto& [c, freq] : count) {
      result += freq & ~0x1;
      offset |= freq & 0x1;
    }
    return result + offset;
  }
};
// @lc code=end
