/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxProduct(const std::vector<int>& nums) {
    auto result = nums[0], product = 1;
    auto update_result = [&](int num) {
      product *= num;
      result = std::max(product, result);
      if (num == 0) {
        product = 1;
      }
    };
    std::for_each(nums.begin(), nums.end(), update_result);
    product = 1;
    std::for_each(nums.rbegin(), nums.rend(), update_result);
    return result;
  }
};
// @lc code=end
