/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  /*
   *  c2 c1 x  ->  c2 c1
   *  0  0  0  ->  0  0
   *  0  1  0  ->  0  1
   *  1  0  0  ->  1  0
   *  0  0  1  ->  0  1
   *  0  1  1  ->  1  0
   *  1  0  1  ->  0  0
   */
  int singleNumber(const std::vector<int>& nums) {
    int c1 = 0, c2 = 0;
    for (auto x : nums) {
      c1 = ~c2 & (c1 ^ x);
      c2 = ~c1 & (c2 ^ x);
    }
    return c1;
  }
};
// @lc code=end
