/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int findPeakElement(const std::vector<int>& nums) {
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (mid == 0 || nums[mid] > nums[mid - 1]) {
        if (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) {
          return mid;
        }
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }
};
// @lc code=end
