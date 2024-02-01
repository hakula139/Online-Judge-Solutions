/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> intersect(
      const std::vector<int>& nums1, const std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }

    std::unordered_map<int, int> set1;
    for (auto num : nums1) {
      ++set1[num];
    }
    std::vector<int> result;
    for (auto num : nums2) {
      auto it = set1.find(num);
      if (it != set1.end()) {
        result.push_back(num);
        if (--it->second == 0) {
          set1.erase(num);
        }
      }
    }
    return result;
  }
};
// @lc code=end
