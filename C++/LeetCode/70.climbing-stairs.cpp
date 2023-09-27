/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    int cur = 1, prev = 1;
    for (int i = 2; i <= n; ++i) {
      int tmp = cur + prev;
      prev = cur;
      cur = tmp;
    }
    return cur;
  }
};
// @lc code=end
