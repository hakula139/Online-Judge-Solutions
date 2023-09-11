/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::string convert(const std::string& s, int num_rows) {
    if (num_rows == 1) return s;

    std::vector<std::string> rows(num_rows);
    for (int i = 0; i < s.size(); ++i) {
      auto r = i % (2 * (num_rows - 1));
      if (r > num_rows - 1) {
        r = 2 * (num_rows - 1) - r;
      }
      rows[r] += s[i];
    }

    std::string result;
    result.reserve(s.size());
    for (auto&& row : rows) {
      result += row;
    }
    return result;
  }
};
// @lc code=end
