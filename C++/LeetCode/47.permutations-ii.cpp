/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <deque>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permuteUnique(const std::vector<int>& nums) {
    std::deque<std::vector<int>> result{{}};
    auto sorted_nums = nums;
    std::sort(sorted_nums.begin(), sorted_nums.end());
    for (auto num : sorted_nums) {
      for (int n = result.size(); n > 0; --n) {
        auto permutation = result.front();
        result.pop_front();
        permutation.push_back(num);
        result.push_back(permutation);
        for (int i = permutation.size() - 1; i > 0; --i) {
          if (permutation[i] == permutation[i - 1]) break;
          std::swap(permutation[i], permutation[i - 1]);
          result.push_back(permutation);
        }
      }
    }
    return {result.begin(), result.end()};
  }
};
// @lc code=end
