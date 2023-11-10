/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  std::string largestNumber(const std::vector<int>& nums) {
    std::vector<std::string> num_strs;
    num_strs.reserve(nums.size());
    for (auto num : nums) {
      num_strs.emplace_back(std::to_string(num));
    }
    std::sort(
        num_strs.begin(), num_strs.end(),
        [](const std::string& lhs, const std::string& rhs) {
          return lhs + rhs > rhs + lhs;
        });

    if (num_strs[0] == "0") return "0";
    std::string result;
    for (const auto& str : num_strs) {
      result += str;
    }
    return result;
  }
};
// @lc code=end
