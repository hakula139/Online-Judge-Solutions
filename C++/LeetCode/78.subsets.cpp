/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<std::vector<int>> result{{}};
    for (auto num : nums) {
      auto sub_size = result.size();
      result.reserve(sub_size << 1);
      for (int i = 0; i < sub_size; ++i) {
        auto sub_result = result[i];
        sub_result.push_back(num);
        result.emplace_back(std::move(sub_result));
      }
    }
    return result;
  }
};
// @lc code=end
