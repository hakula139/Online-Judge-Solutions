/*
 * @lc app=leetcode id=397 lang=cpp
 *
 * [397] Integer Replacement
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  int integerReplacement(int64_t n) {
    int count = 0;
    while (n > 1) {
      auto r = n & 0x3;
      if (r == 1 || n == 3) {
        --n;
      } else if (r == 3) {
        ++n;
      } else {
        n >>= 1;
      }
      ++count;
    }
    return count;
  }
};
// @lc code=end
