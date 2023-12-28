/*
 * @lc app=leetcode id=324 lang=cpp
 *
 * [324] Wiggle Sort II
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  void wiggleSort(std::vector<int>& nums) {
    auto n = nums.size();
    /**
     * From: 0 1 2 3 4 5
     * To:   1 3 5 0 2 4
     */
    auto wiggled_nums = [&](int i) -> int& {
      return nums[(i * 2 + 1) % (n | 1)];
    };
    auto mid_it = nums.begin() + n / 2;
    std::nth_element(nums.begin(), mid_it, nums.end());
    auto median = *mid_it;
    int i = 0, j = 0, k = n - 1;
    while (j <= k) {
      auto& cur = wiggled_nums(j);
      if (cur < median) {
        std::swap(cur, wiggled_nums(k--));
      } else {
        if (cur > median) {
          std::swap(cur, wiggled_nums(i++));
        }
        ++j;
      }
    }
  }
};
// @lc code=end
