/*
 * @lc app=leetcode id=479 lang=cpp
 *
 * [479] Largest Palindrome Product
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  int largestPalindrome(int n) {
    constexpr int k = 1337;
    int64_t pow_10_n = std::pow(10, n);
    auto min = pow_10_n / 10, max = pow_10_n - 1;
    for (auto left = max; left >= min; --left) {
      auto palindrome = left * pow_10_n + reverse(left);
      if (isProduct(palindrome, min, max)) {
        return palindrome % k;
      }
    }
    for (auto left = max; left >= min; --left) {
      auto palindrome = left / 10 * pow_10_n + reverse(left);
      if (isProduct(palindrome, min, max)) {
        return palindrome % k;
      }
    }
    // Should not reach here.
    return 0;
  }

 private:
  int64_t reverse(int64_t x) {
    int64_t result = 0;
    for (; x; x /= 10) {
      result = result * 10 + x % 10;
    }
    return result;
  }

  bool isProduct(int64_t x, int64_t min, int64_t max) {
    for (int64_t factor = std::ceil(std::sqrt(x)); factor <= max; ++factor) {
      if (x / factor < min) break;
      if (x % factor == 0) return true;
    }
    return false;
  }
};
// @lc code=end
