/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
    auto n = nums.size();
    std::vector<int> result;
    for (int i = 1; i <= n; ++i) {
      if (i == nums[i - 1]) continue;
      while (nums[i - 1] != nums[nums[i - 1] - 1]) {
        std::swap(nums[i - 1], nums[nums[i - 1] - 1]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i != nums[i - 1]) {
        result.push_back(i);
      }
    }
    return result;
  }
};
// @lc code=end
