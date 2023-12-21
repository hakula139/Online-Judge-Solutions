/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::string removeDuplicateLetters(const std::string& s) {
    std::vector last_seen(26, -1);
    std::vector has_seen(26, false);
    std::string result;
    result.reserve(s.size());

    for (int i = 0; i < s.size(); ++i) {
      last_seen[s[i] - 'a'] = i;
    }
    for (int i = 0; i < s.size(); ++i) {
      if (has_seen[s[i] - 'a']) continue;
      while (result.size() && result.back() >= s[i] &&
             last_seen[result.back() - 'a'] > i) {
        has_seen[result.back() - 'a'] = false;
        result.pop_back();
      }
      has_seen[s[i] - 'a'] = true;
      result += s[i];
    }
    return result;
  }
};
// @lc code=end
