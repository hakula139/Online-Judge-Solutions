/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
 public:
  int getSum(int a, int b) {
    while (b) {
      auto sum = a ^ b;
      b = (a & b) << 1;
      a = sum;
    }
    return a;
  }
};
// @lc code=end
