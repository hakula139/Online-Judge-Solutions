/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
 public:
  int addDigits(int num) {
    if (!num) return 0;
    int r = num % 9;
    return r ? r : 9;
  }
};
// @lc code=end
