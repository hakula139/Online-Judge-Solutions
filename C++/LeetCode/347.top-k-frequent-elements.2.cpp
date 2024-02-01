/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (auto num : nums) {
      ++count[num];
    }

    std::vector<std::vector<int>> buckets(nums.size() + 1);
    for (const auto& [num, freq] : count) {
      buckets[freq].push_back(num);
    }

    std::vector<int> result;
    result.reserve(k);
    for (auto it = buckets.rbegin(); it < buckets.rend(); ++it) {
      if (it->empty()) continue;
      for (auto num : *it) {
        result.push_back(num);
        if (result.size() == k) break;
      }
      if (result.size() == k) break;
    }
    return result;
  }
};
// @lc code=end
