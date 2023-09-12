/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::string intToRoman(int num) {
    const std::vector<std::pair<int, std::string>> symbols{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"},
    };

    std::string s;
    for (const auto& [value, symbol] : symbols) {
      while (num >= value) {
        s += symbol;
        num -= value;
      }
    }
    return s;
  }
};
// @lc code=end
