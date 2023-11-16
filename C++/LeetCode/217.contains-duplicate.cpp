/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <unordered_set>
#include <vector>

class Solution {
 public:
  bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> nums_set;
    for (auto num : nums) {
      if (nums_set.contains(num)) return true;
      nums_set.insert(num);
    }
    return false;
  }
};
// @lc code=end
