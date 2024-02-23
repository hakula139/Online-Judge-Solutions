/*
 * @lc app=leetcode id=396 lang=cpp
 *
 * [396] Rotate Function
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int maxRotateFunction(const std::vector<int>& nums) {
    int max_result = 0, result = 0;
    auto sum = std::accumulate(nums.begin(), nums.end(), 0);
    for (int i = 0; i < nums.size(); ++i) {
      result += nums[i] * i;
      max_result = result;
    }
    for (int i = nums.size() - 1; i > 0; --i) {
      result += sum - nums[i] * nums.size();
      max_result = std::max(result, max_result);
    }
    return max_result;
  }
};
// @lc code=end
