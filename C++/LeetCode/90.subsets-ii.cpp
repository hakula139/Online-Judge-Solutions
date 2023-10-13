/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::vector<int> subset;
    std::sort(nums.begin(), nums.end());
    subsetsWithDup(result, subset, nums, 0);
    return result;
  }

 private:
  void subsetsWithDup(
      std::vector<std::vector<int>>& result, std::vector<int>& subset,
      const std::vector<int>& nums, int index) {
    result.push_back(subset);
    for (int i = index; i < nums.size(); ++i) {
      if (i == index || nums[i] != nums[i - 1]) {
        subset.push_back(nums[i]);
        subsetsWithDup(result, subset, nums, i + 1);
        subset.pop_back();
      }
    }
  }
};
// @lc code=end
