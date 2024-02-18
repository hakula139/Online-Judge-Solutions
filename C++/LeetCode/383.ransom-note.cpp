/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  bool canConstruct(
      const std::string& ransom_note, const std::string& magazine) {
    std::vector<int> count(kAlphabetSize);
    for (auto c : magazine) {
      ++count[c - 'a'];
    }
    for (auto c : ransom_note) {
      if (--count[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
