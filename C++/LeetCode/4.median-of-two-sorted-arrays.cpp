/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  double findMedianSortedArrays(const std::vector<int>& nums1,
                                const std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int i1_begin = 0, i1_end = nums1.size();
    int k = (nums1.size() + nums2.size() + 1) / 2;
    while (i1_begin <= i1_end) {
      int mid1 = (i1_begin + i1_end) / 2;
      int mid2 = k - mid1;
      int nums1_max_left = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
      int nums1_min_right = mid1 < nums1.size() ? nums1[mid1] : INT_MAX;
      int nums2_max_left = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
      int nums2_min_right = mid2 < nums2.size() ? nums2[mid2] : INT_MAX;

      if (nums1_max_left > nums2_min_right) {
        i1_end = mid1 - 1;
      } else if (nums2_max_left > nums1_min_right) {
        i1_begin = mid1 + 1;
      } else {
        int max_left = std::max(nums1_max_left, nums2_max_left);
        if ((nums1.size() + nums2.size()) & 0x1) {
          return max_left;
        }
        int min_right = std::min(nums1_min_right, nums2_min_right);
        return (max_left + min_right) / 2.0;
      }
    }
    return 0;
  }
};
// @lc code=end
