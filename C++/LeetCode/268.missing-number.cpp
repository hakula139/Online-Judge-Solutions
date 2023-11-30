/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <numeric>
#include <vector>

class Solution {
 public:
  int missingNumber(const std::vector<int>& nums) {
    int result = std::accumulate(
        nums.begin(), nums.end(), 0, std::bit_xor<int>());
    for (int i = 1; i <= nums.size(); ++i) {
      result ^= i;
    }
    return result;
  }
};
// @lc code=end
