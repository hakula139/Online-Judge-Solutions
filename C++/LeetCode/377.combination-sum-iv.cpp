/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <vector>

constexpr int kIntMax = 1000;

class Solution {
 public:
  Solution() : mem_(kIntMax + 1, -1) {}

  int combinationSum4(const std::vector<int>& nums, int target) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    if (mem_[target] >= 0) return mem_[target];

    int sum = 0;
    for (auto num : nums) {
      sum += combinationSum4(nums, target - num);
    }
    mem_[target] = sum;
    return sum;
  }

 private:
  std::vector<int> mem_;
};
// @lc code=end
