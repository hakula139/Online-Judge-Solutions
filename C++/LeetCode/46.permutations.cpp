/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <deque>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> permute(const std::vector<int>& nums) {
    std::deque<std::vector<int>> result{{}};
    for (auto num : nums) {
      for (int n = result.size(); n > 0; --n) {
        auto permutation = result.front();
        result.pop_front();
        permutation.push_back(num);
        result.push_back(permutation);
        for (int i = permutation.size() - 1; i > 0; --i) {
          std::swap(permutation[i], permutation[i - 1]);
          result.push_back(permutation);
        }
      }
    }
    return {result.begin(), result.end()};
  }
};
// @lc code=end
