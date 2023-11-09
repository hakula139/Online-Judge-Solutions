/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
 public:
  int trailingZeroes(int n) {
    int result = 0;
    while (n) {
      n /= 5;
      result += n;
    }
    return result;
  }
};
// @lc code=end
