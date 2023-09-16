/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> searchRange(const std::vector<int>& nums, int target) {
    std::vector<int> range{-1, -1};
    int begin = 0, end = nums.size();
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (target == nums[mid]) {
        range[0] = range[1] = mid;
        break;
      }
      if (target < nums[mid]) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }

    if (range[0] < 0) return range;
    for (int i = begin, j = range[0]; i < j;) {
      int mid = i + (j - i) / 2;
      if (target == nums[mid]) {
        range[0] = mid;
        j = mid;
      } else {
        i = mid + 1;
      }
    }
    for (int i = range[1], j = end; i < j;) {
      int mid = i + (j - i) / 2;
      if (target == nums[mid]) {
        range[1] = mid;
        i = mid + 1;
      } else {
        j = mid;
      }
    }
    return range;
  }
};
// @lc code=end
