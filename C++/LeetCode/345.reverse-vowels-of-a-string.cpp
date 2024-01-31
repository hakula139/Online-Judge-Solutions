/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <utility>

class Solution {
 public:
  std::string reverseVowels(std::string& s) {
    const std::unordered_set<char> vowels{
        'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U',
    };
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      for (; i < j && !vowels.contains(s[i]); ++i) {
      }
      for (; i < j && !vowels.contains(s[j]); --j) {
      }
      std::swap(s[i], s[j]);
    }
    return s;
  }
};
// @lc code=end
