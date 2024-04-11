/*
 * @lc app=leetcode id=481 lang=cpp
 *
 * [481] Magical String
 */

// @lc code=start
#include <queue>

class Solution {
 public:
  int magicalString(int n) {
    std::queue<int> s;
    int result = 0, cur = 1, len = 0;
    for (; len < n; s.pop()) {
      auto count = s.empty() ? cur : s.front();
      len += count;
      if (cur == 1) {
        result += count;
      }
      for (; count > 0; --count) {
        s.push(cur);
      }
      cur = cur == 1 ? 2 : 1;
    }
    if (len > n && cur == 2) {
      result -= len - n;
    }
    return result;
  }
};
// @lc code=end
