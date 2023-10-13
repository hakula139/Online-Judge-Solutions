/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> grayCode(int n) {
    std::vector<int> result(1 << n);
    for (int i = 0; i < result.size(); ++i) {
      result[i] = i ^ (i >> 1);
    }
    return result;
  }
};
// @lc code=end
