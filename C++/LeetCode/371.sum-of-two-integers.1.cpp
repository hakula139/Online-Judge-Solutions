/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
 public:
  int getSum(int a, int b) {
    auto result = 0U, carry = 0U;
    auto i = 1ULL, i_end = i << 32;
    for (; i < i_end; i <<= 1, carry <<= 1) {
      auto digit_a = a & i, digit_b = b & i;
      result |= digit_a ^ digit_b ^ carry;
      carry = (digit_a & digit_b) | (digit_a & carry) | (digit_b & carry);
    }
    return result;
  }
};
// @lc code=end
