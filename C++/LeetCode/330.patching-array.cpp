/*
 * @lc app=leetcode id=330 lang=cpp
 *
 * [330] Patching Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int minPatches(std::vector<int>& nums, int n) {
    int result = 0;
    int64_t max_reached = 0;
    nums.push_back(n);
    for (auto num : nums) {
      while (max_reached < num - 1 && max_reached < n) {
        ++result;
        max_reached += max_reached + 1;
      }
      max_reached += num;
      if (max_reached >= n) break;
    }
    return result;
  }
};
// @lc code=end
