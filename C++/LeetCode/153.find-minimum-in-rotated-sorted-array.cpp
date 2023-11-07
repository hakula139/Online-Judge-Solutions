/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
      } else {
        end = mid;
      }
    }
    return nums[begin];
  }
};
// @lc code=end
