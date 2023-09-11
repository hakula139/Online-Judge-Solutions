/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <limits>
#include <string>

class Solution {
 public:
  int myAtoi(const std::string& s) {
    bool is_positive = true;
    bool is_leading = true;
    int64_t result = 0;

    for (auto c : s) {
      if (c >= '0' && c <= '9') {
        is_leading = false;
        result = result * 10 + c - '0';
        if (is_positive) {
          if (result > INT32_MAX) return INT32_MAX;
        } else {
          if (-result < INT32_MIN) return INT32_MIN;
        }
      } else if (is_leading) {
        switch (c) {
          case ' ':
            continue;
          case '-':
            is_positive = false;
            // fallthrough
          case '+':
            is_leading = false;
            break;
          default:
            return 0;
        }
      } else {
        break;
      }
    }

    return is_positive ? result : -result;
  }
};
// @lc code=end
