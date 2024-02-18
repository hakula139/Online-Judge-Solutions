/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */

// @lc code=start
#include <random>
#include <utility>
#include <vector>

class Solution {
 public:
  explicit Solution(const std::vector<int>& nums) : nums_{nums} {}

  std::vector<int> reset() { return nums_; }

  std::vector<int> shuffle() {
    auto result = nums_;
    for (int i = 0; i < result.size(); ++i) {
      std::uniform_int_distribution dist(0, i);
      std::swap(result[i], result[dist(rng_)]);
    }
    return result;
  }

 private:
  std::vector<int> nums_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
