/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    if (nums.size() < 4) return result;

    std::sort(nums.begin(), nums.end());

    for (int i1 = 0; i1 < nums.size() - 3; ++i1) {
      int n1 = nums[i1];
      for (int i2 = i1 + 1; i2 < nums.size() - 2; ++i2) {
        int n2 = nums[i2];
        int i3 = i2 + 1, i4 = nums.size() - 1;
        while (i3 < i4) {
          int n3 = nums[i3], n4 = nums[i4];
          auto sum = static_cast<int64_t>(n1) + n2 + n3 + n4;
          if (sum == target) {
            result.push_back({n1, n2, n3, n4});
          }
          if (sum <= target) {
            for (; i3 < i4 && nums[i3 + 1] == n3; ++i3) {
            }
            ++i3;
          }
          if (sum >= target) {
            for (; i3 < i4 && nums[i4 - 1] == n4; --i4) {
            }
            --i4;
          }
        }
        for (; i2 < nums.size() - 2 && nums[i2 + 1] == n2; ++i2) {
        }
      }
      for (; i1 < nums.size() - 3 && nums[i1 + 1] == n1; ++i1) {
      }
    }
    return result;
  }
};
// @lc code=end
