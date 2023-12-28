/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    // 1162261467 = 3^19, which is the largest power of 3 in 32-bit integers.
    return n > 0 && 1162261467 % n == 0;
  }
};
// @lc code=end
