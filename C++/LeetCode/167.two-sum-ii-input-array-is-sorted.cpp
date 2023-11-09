/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> twoSum(const std::vector<int>& numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      auto sum = numbers[i] + numbers[j];
      if (sum == target) break;
      if (sum < target) {
        ++i;
      } else {
        --j;
      }
    }
    return {i + 1, j + 1};
  }
};
// @lc code=end
