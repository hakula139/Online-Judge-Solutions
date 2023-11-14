/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
#include <algorithm>
#include <queue>
#include <vector>

class Solution {
 public:
  int minSubArrayLen(int target, const std::vector<int>& nums) {
    auto min_len = nums.size() + 1;
    std::queue<int> q;
    int i = 0, sum = 0;
    while (i < nums.size()) {
      for (; i < nums.size() && sum < target; ++i) {
        q.push(nums[i]);
        sum += nums[i];
      }
      if (sum < target) break;
      while (q.size() && sum >= target) {
        sum -= q.front();
        q.pop();
      }
      min_len = std::min(q.size() + 1, min_len);
    }
    return min_len <= nums.size() ? min_len : 0;
  }
};
// @lc code=end
