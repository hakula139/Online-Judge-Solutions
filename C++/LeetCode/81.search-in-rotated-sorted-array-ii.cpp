/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool search(std::vector<int>& nums, int target) {
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid]) return true;
      while (begin < end && nums[begin] == nums[mid] &&
             nums[mid] == nums[end - 1]) {
        ++begin, --end;
      }
      if (begin >= end) break;
      if (nums[begin] <= nums[mid]) {
        if (target == nums[begin]) return true;
        if (target < nums[mid] && target > nums[begin]) {
          ++begin, end = mid;
        } else {
          begin = mid + 1;
        }
      } else if (nums[mid] <= nums[end - 1]) {
        if (target == nums[end - 1]) return true;
        if (target < nums[end - 1] && target > nums[mid]) {
          begin = mid + 1, --end;
        } else {
          end = mid;
        }
      }
    }
    return false;
  }
};
// @lc code=end
