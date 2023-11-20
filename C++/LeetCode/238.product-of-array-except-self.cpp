/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    std::vector<int> result(nums.size(), 1);
    for (int i = 1; i < nums.size(); ++i) {
      result[i] = result[i - 1] * nums[i - 1];
    }
    int product = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      result[i] *= product;
      product *= nums[i];
    }
    return result;
  }
};
// @lc code=end
