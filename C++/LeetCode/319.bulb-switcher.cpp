/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  int bulbSwitch(int n) {
    /**
     * On the i-th round, bulb x is toggled iff i divides x. After all rounds,
     * bulb x is on iff x has been toggled odd number of times, so there should
     * be odd number of i's from range [1, x] which divides x. Notice that only
     * perfect squares have odd number of factors. Therefore the final answer is
     * the number of perfect squares not larger than n.
     */
    return std::sqrt(n);
  }
};
// @lc code=end
