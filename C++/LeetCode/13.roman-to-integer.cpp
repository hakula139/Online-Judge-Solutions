/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  int romanToInt(const std::string& s) {
    const std::unordered_map<char, int> values{
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
        {'X', 10},   {'V', 5},   {'I', 1},
    };

    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      auto value = values.at(s[i]);
      if (i < s.size() - 1 && value < values.at(s[i + 1])) {
        num -= value;
      } else {
        num += value;
      }
    }
    return num;
  }
};
// @lc code=end
