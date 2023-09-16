/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int searchInsert(const std::vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid]) {
        begin = mid;
        break;
      }
      if (target < nums[mid]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};
// @lc code=end
