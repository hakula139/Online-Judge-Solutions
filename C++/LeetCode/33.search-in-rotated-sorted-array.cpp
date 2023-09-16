/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int search(const std::vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid]) return mid;
      if (nums[begin] <= nums[mid]) {
        if (target == nums[begin]) return begin;
        if (target < nums[mid] && target > nums[begin]) {
          ++begin, end = mid;
        } else {
          begin = mid + 1;
        }
      } else {
        if (target == nums[end - 1]) return end - 1;
        if (target < nums[end - 1] && target > nums[mid]) {
          begin = mid + 1, --end;
        } else {
          end = mid;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
