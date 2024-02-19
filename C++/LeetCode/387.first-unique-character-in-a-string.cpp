/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  int firstUniqChar(const std::string& s) {
    std::vector<int> count(kAlphabetSize);
    for (auto c : s) {
      ++count[c - 'a'];
    }
    for (int i = 0; i < s.size(); ++i) {
      if (count[s[i] - 'a'] == 1) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
