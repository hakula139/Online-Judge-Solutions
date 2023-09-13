/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
#include <algorithm>
#include <cmath>
#include <vector>

class Solution {
 public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    int result = 0, min_dist = INT_MAX;
    for (int i = 0; i < nums.size() - 2; ++i) {
      int n1 = nums[i];
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int n2 = nums[j], n3 = nums[k];
        int sum = n1 + n2 + n3;
        if (sum == target) return sum;

        int dist = std::abs(sum - target);
        if (dist < min_dist) {
          result = sum, min_dist = dist;
        }
        if (sum < target) {
          ++j;
        } else {
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
