/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int findMin(const std::vector<int>& nums) {
    int begin = 0, end = nums.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (nums[mid] > nums[end]) {
        begin = mid + 1;
      } else if (nums[mid] < nums[end]) {
        end = mid;
      } else {
        --end;
      }
    }
    return nums[begin];
  }
};
// @lc code=end
