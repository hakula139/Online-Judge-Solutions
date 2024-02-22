/*
 * @lc app=leetcode id=390 lang=cpp
 *
 * [390] Elimination Game
 */

// @lc code=start
class Solution {
 public:
  int lastRemaining(int n) {
    int m = 1, r = 1;
    bool is_left = true;
    for (; n > 1; n >>= 1) {
      if (is_left || n % 2) {
        r += m;
      }
      m <<= 1;
      is_left = !is_left;
    }
    return r;
  }
};
// @lc code=end
