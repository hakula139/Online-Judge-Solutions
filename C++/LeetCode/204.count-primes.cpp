/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#include <cmath>
#include <vector>

class Solution {
 public:
  int countPrimes(int n) {
    std::vector<bool> is_prime(n, true);
    int sqrt_n = std::sqrt(n);
    for (int i = 2; i <= sqrt_n; ++i) {
      if (!is_prime[i]) continue;
      for (int j = i * i; j < n; j += i) {
        is_prime[j] = false;
      }
    }

    int result = 0;
    for (int i = 2; i < n; ++i) {
      if (is_prime[i]) {
        ++result;
      }
    }
    return result;
  }
};
// @lc code=end
