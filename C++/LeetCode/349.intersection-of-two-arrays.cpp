/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(
      const std::vector<int>& nums1, const std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersection(nums2, nums1);
    }

    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::vector<int> result;
    for (auto num : nums2) {
      if (set1.contains(num)) {
        result.push_back(num);
        set1.erase(num);
      }
    }
    return result;
  }
};
// @lc code=end
