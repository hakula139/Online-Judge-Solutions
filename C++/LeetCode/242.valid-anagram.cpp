/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, int> count;
    for (auto c : s) {
      ++count[c];
    }
    for (auto c : t) {
      if (--count[c] == 0) {
        count.erase(c);
      }
    }
    return count.empty();
  }
};
// @lc code=end
