/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
#include <unordered_set>

class Solution {
 public:
  bool isHappy(int n) {
    std::unordered_set<int> set;
    while (n != 1) {
      int next_n = 0;
      while (n) {
        int d = n % 10;
        next_n += d * d;
        n /= 10;
      }
      n = next_n;
      if (set.contains(n)) return false;
      set.insert(n);
    }
    return true;
  }
};
// @lc code=end
