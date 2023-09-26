/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
#include <string>

class Solution {
 public:
  std::string getPermutation(int n, int k) {
    int fact_n = 1;
    std::string s;
    for (int i = 1; i <= n; ++i) {
      fact_n *= i;
      s += '0' + i;
    }
    --k;

    for (int i = 0; i < n - 1; ++i) {
      fact_n /= n - i;
      auto c_i = i + k / fact_n;
      k %= fact_n;
      auto c = s[c_i];
      for (int j = c_i; j > i; --j) {
        s[j] = s[j - 1];
      }
      s[i] = c;
    }
    return s;
  }
};
// @lc code=end
