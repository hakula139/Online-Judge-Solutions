/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int hIndex(const std::vector<int>& citations) {
    int n = citations.size();
    std::vector<int> count(n + 1);
    for (auto c : citations) {
      if (c >= n) {
        ++count[n];
      } else {
        ++count[c];
      }
    }
    for (int i = n; i > 0; --i) {
      if (count[i] >= i) return i;
      count[i - 1] += count[i];
    }
    return 0;
  }
};
// @lc code=end
