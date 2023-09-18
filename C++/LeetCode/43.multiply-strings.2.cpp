/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string multiply(const std::string& num1, const std::string& num2) {
    if (num1 == "0" || num2 == "0") return "0";

    std::vector<int> result(num1.size() + num2.size());
    for (int i = 0; i < num1.size(); ++i) {
      for (int j = 0; j < num2.size(); ++j) {
        int k = num1.size() - i + num2.size() - j - 2;
        result[k] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    for (int k = 0; k < result.size() - 1; ++k) {
      result[k + 1] += result[k] / 10;
      result[k] %= 10;
    }
    if (result.back() == 0) {
      result.pop_back();
    }

    std::string s;
    s.reserve(result.size());
    for (auto it = result.rbegin(); it < result.rend(); ++it) {
      s += '0' + *it;
    }
    return s;
  }
};
// @lc code=end
