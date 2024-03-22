/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int fourSumCount(
      const std::vector<int>& nums1, const std::vector<int>& nums2,
      const std::vector<int>& nums3, const std::vector<int>& nums4) {
    std::unordered_map<int, int> map1, map2, map3, map4;
    for (auto num : nums1) ++map1[num];
    for (auto num : nums2) ++map2[num];
    for (auto num : nums3) ++map3[num];
    for (auto num : nums4) ++map4[num];

    std::unordered_map<int, int> map12, map34;
    for (const auto& [num1, count1] : map1) {
      for (const auto& [num2, count2] : map2) {
        map12[num1 + num2] += count1 * count2;
      }
    }
    for (const auto& [num3, count3] : map3) {
      for (const auto& [num4, count4] : map4) {
        map34[num3 + num4] += count3 * count4;
      }
    }

    int result = 0;
    for (const auto& [sum12, count12] : map12) {
      auto it = map34.find(-sum12);
      if (it != map34.end()) {
        result += count12 * it->second;
      }
    }
    return result;
  }
};
// @lc code=end
