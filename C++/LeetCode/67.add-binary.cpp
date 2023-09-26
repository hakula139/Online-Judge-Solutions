/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  std::string addBinary(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
      int d1 = i >= 0 ? a[i] - '0' : 0;
      int d2 = j >= 0 ? b[j] - '0' : 0;
      int sum = d1 + d2 + carry;
      if (sum >= 2) {
        sum -= 2;
        carry = 1;
      } else {
        carry = 0;
      }
      result += '0' + sum;
    }
    if (carry) {
      result += '1';
    }
    std::reverse(result.begin(), result.end());
    return result;
  }
};
// @lc code=end
