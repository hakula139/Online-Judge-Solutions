/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <cmath>
#include <functional>
#include <vector>

class Solution {
 public:
  double myPow(double x, int n) {
    double result = 1.0;
    if (n == 0 || x == 1.0) return result;

    auto abs_n = std::abs(static_cast<int64_t>(n));
    auto op = n > 0 ? std::function{std::multiplies<double>()}
                    : std::function{std::divides<double>()};
    while (abs_n > 0) {
      if (abs_n & 0x1) {
        result = op(result, x);
        --abs_n;
      } else {
        x *= x;
        abs_n >>= 1;
      }
    }
    return result;
  }
};
// @lc code=end
