/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> countBits(int n) {
    std::vector<int> bits(n + 1);
    for (int i = 0; i <= n; ++i) {
      bits[i] = bits[i >> 1] + (i & 1);
    }
    return bits;
  }
};
// @lc code=end
