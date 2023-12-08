/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> seq;
    for (auto num : nums) {
      if (seq.empty() || num > seq.back()) {
        seq.push_back(num);
      } else {
        auto it = std::lower_bound(seq.begin(), seq.end(), num);
        *it = num;
      }
    }
    return seq.size();
  }
};
// @lc code=end
