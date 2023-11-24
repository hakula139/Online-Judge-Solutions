/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
#include <initializer_list>

class Solution {
 public:
  bool isUgly(int n) {
    if (n <= 0) return false;
    for (auto prime : {2, 3, 5}) {
      while (n % prime == 0) {
        n /= prime;
      }
    }
    return n == 1;
  }
};
// @lc code=end
