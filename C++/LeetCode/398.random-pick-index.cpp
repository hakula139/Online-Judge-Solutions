/*
 * @lc app=leetcode id=398 lang=cpp
 *
 * [398] Random Pick Index
 */

// @lc code=start
#include <random>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  explicit Solution(const std::vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      indices_[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    const auto& v = indices_[target];
    std::uniform_int_distribution<int> dist(0, v.size() - 1);
    return v[dist(rng_)];
  }

 private:
  std::unordered_map<int, std::vector<int>> indices_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
