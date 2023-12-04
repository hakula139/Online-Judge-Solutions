/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <cmath>

class Solution {
 public:
  int numSquares(int n) {
    int result = n, k = 0;
    bt(n, k, result);
    return result;
  }

 private:
  void bt(int n, int& k, int& result) {
    if (n == 0) {
      result = k;
      return;
    }
    if (k >= result - 1) return;

    ++k;
    for (int i = std::sqrt(n); i > 0; --i) {
      bt(n - i * i, k, result);
    }
    --k;
  }
};
// @lc code=end
