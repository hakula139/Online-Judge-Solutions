/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> reverted_idx;
    for (int i = 0; i < nums.size(); ++i) {
      auto it = reverted_idx.find(target - nums[i]);
      if (it != reverted_idx.end()) {
        return {i, it->second};
      }
      reverted_idx[nums[i]] = i;
    }
    return {};
  }
};
// @lc code=end
