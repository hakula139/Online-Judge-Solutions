/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  bool isIsomorphic(const std::string& s, const std::string& t) {
    std::unordered_map<char, char> s_map, t_map;
    for (int i = 0; i < s.size(); ++i) {
      auto it = s_map.find(s[i]);
      if (it != s_map.end() && it->second != t[i]) {
        return false;
      }
      s_map[s[i]] = t[i];

      it = t_map.find(t[i]);
      if (it != t_map.end() && it->second != s[i]) {
        return false;
      }
      t_map[t[i]] = s[i];
    }
    return true;
  }
};
// @lc code=end
