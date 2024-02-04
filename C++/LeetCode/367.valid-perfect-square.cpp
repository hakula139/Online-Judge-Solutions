/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
#include <cstdint>

class Solution {
 public:
  bool isPerfectSquare(int num) {
    int64_t begin = 1, end = num;
    while (begin <= end) {
      auto mid = begin + (end - begin) / 2;
      auto product = mid * mid;
      if (num == product) return true;
      if (num < product) {
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
    }
    return false;
  }
};
// @lc code=end
