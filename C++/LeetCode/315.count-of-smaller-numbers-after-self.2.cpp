/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> countSmaller(const std::vector<int>& nums) {
    auto n = nums.size();
    std::vector<int> result(n);
    auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
    if (*min_it == *max_it) return result;

    auto min = *min_it - 1, max = *max_it;
    count_ = std::vector<int>(max - min + 1);
    for (int i = n - 1; i >= 0; --i) {
      auto x = nums[i] - min;  // normalize
      result[i] = get(x - 1);
      update(x);
    }
    return result;
  }

 private:
  // Least Significant Bit
  int lsb(int x) const { return x & -x; }

  // Increment count of x by 1.
  void update(int x) {
    for (; x < count_.size(); x += lsb(x)) {
      ++count_[x];
    }
  }

  // Count of numbers <= x.
  int get(int x) const {
    int result = 0;
    for (; x > 0; x -= lsb(x)) {
      result += count_[x];
    }
    return result;
  }

  std::vector<int> count_;  // Binary Indexed Tree (Fenwick Tree)
};
// @lc code=end
