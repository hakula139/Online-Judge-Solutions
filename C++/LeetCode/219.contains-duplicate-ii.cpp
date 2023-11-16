/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  bool containsNearbyDuplicate(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> nums_set;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = nums_set.find(nums[i]);
      if (it == nums_set.end()) {
        nums_set[nums[i]] = i;
      } else if (i <= it->second + k) {
        return true;
      } else {
        it->second = i;
      }
    }
    return false;
  }
};
// @lc code=end
