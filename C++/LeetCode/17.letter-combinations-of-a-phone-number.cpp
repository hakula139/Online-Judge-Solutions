/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> letterCombinations(const std::string& digits) {
    const std::vector<std::string> mappings{
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };

    std::vector<std::string> result{""};
    for (auto digit : digits) {
      std::vector<std::string> new_result;
      new_result.reserve(result.size() * 4);
      for (const auto& s : result) {
        for (auto c : mappings.at(digit - '2')) {
          new_result.push_back(s + c);
        }
      }
      result = new_result;
    }
    return result.size() > 1 ? result : std::vector<std::string>{};
  }
};
// @lc code=end
