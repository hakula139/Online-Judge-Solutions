/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
#include <array>
#include <vector>

class Solution {
 public:
  bool increasingTriplet(const std::vector<int>& nums) {
    if (nums.size() < 3) return false;
    std::array result{INT_MAX, INT_MAX};
    for (auto num : nums) {
      if (num <= result[0]) {
        result[0] = num;
      } else if (num <= result[1]) {
        result[1] = num;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
