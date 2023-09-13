/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int n1 = nums[i];
      if (n1 > 0) break;

      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int n2 = nums[j], n3 = nums[k];
        int sum = n1 + n2 + n3;
        if (sum == 0) {
          result.push_back({n1, n2, n3});
        }
        if (sum <= 0) {
          for (; j < k && nums[j + 1] == n2; ++j) {
          }
          ++j;
        }
        if (sum >= 0) {
          for (; j < k && nums[k - 1] == n3; --k) {
          }
          --k;
        }
      }
      for (; i < nums.size() - 2 && nums[i + 1] == n1; ++i) {
      }
    }
    return result;
  }
};
// @lc code=end
