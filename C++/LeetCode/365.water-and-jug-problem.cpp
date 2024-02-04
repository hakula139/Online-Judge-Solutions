/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
#include <numeric>

class Solution {
 public:
  bool canMeasureWater(int jug1_capacity, int jug2_capacity, int target) {
    return target <= jug1_capacity + jug2_capacity &&
           target % std::gcd(jug1_capacity, jug2_capacity) == 0;
  }
};
// @lc code=end
