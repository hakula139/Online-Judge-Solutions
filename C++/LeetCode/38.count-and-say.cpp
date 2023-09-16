/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
#include <string>

class Solution {
 public:
  std::string countAndSay(int n) {
    std::string result = "1";
    while (--n) {
      std::string s;
      auto num = result[0];
      int count = 1;
      for (int i = 1; i < result.size(); ++i) {
        if (result[i] == result[i - 1]) {
          ++count;
        } else {
          s += std::to_string(count) + num;
          num = result[i];
          count = 1;
        }
      }
      s += std::to_string(count) + num;
      result = s;
    }
    return result;
  }
};
// @lc code=end
