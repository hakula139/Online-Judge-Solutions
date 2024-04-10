/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
    auto mask = 1U;
    for (int x = num; x; x >>= 1, mask <<= 1) {
    }
    return ~num & --mask;
  }
};
// @lc code=end
