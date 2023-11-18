/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> summaryRanges(const std::vector<int>& nums) {
    if (nums.empty()) return {};

    std::vector<std::string> result;
    int begin = nums[0], end = nums[0];
    auto add_result = [&]() {
      result.emplace_back(std::to_string(begin));
      if (begin < end) {
        result.back() += "->" + std::to_string(end);
      }
    };

    for (auto num : nums) {
      if (num > end + 1) {
        add_result();
        begin = end = num;
      } else {
        end = num;
      }
    }
    add_result();
    return result;
  }
};
// @lc code=end
