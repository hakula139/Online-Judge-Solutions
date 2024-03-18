/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 */

// @lc code=start
#include <algorithm>

class Solution {
 public:
  int findKthNumber(int n, int k) {
    int result = 1;
    for (--k; k > 0;) {
      int next = result + 1;
      auto gap = findGap(result, next, n);
      if (k >= gap) {
        ++result;
        k -= gap;
      } else {
        result *= 10;
        k--;
      }
    }
    return result;
  }

 private:
  int64_t findGap(int64_t begin, int64_t end, int64_t n) {
    int64_t gap = 0;
    while (begin <= n) {
      gap += std::min(end, n + 1) - begin;
      begin *= 10;
      end *= 10;
    }
    return gap;
  }
};
// @lc code=end
