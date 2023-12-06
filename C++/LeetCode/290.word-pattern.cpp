/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  bool wordPattern(const std::string& pattern, const std::string& s) {
    std::vector<std::string> p_dict(26);
    std::unordered_map<std::string, char> s_dict;

    auto begin = s.begin();
    for (auto c : pattern) {
      if (begin == s.end()) return false;
      auto end = std::find(begin, s.end(), ' ');
      std::string word{begin, end};
      begin = end == s.end() ? end : end + 1;

      auto it = s_dict.find(word);
      if (it == s_dict.end()) {
        auto& v = p_dict[c - 'a'];
        if (v.size()) return false;
        s_dict[word] = c;
        v = std::move(word);
      } else if (it->second != c) {
        return false;
      }
    }
    return begin == s.end();
  }
};
// @lc code=end
