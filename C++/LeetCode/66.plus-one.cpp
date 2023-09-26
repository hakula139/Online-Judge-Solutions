/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> plusOne(std::vector<int>& digits) {
    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; --i) {
      digits[i] += carry;
      if (digits[i] >= 10) {
        digits[i] -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (carry) {
      digits.insert(digits.begin(), carry);
    }
    return digits;
  }
};
// @lc code=end
