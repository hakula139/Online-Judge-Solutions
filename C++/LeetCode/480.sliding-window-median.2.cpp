/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
#include <functional>
#include <numeric>
#include <set>
#include <vector>

class Solution {
 public:
  using It = std::multiset<int>::iterator;

  std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k) {
    if (k == 1) return {nums.begin(), nums.end()};

    std::multiset window(nums.begin(), nums.begin() + k);
    auto mid_it = std::next(window.begin(), k / 2);
    std::vector<double> result;
    auto get_median = std::mem_fn(
        k % 2 ? &Solution::oddMedian : &Solution::evenMedian);

    for (int i = k; i < nums.size(); ++i) {
      result.push_back(get_median(*this, mid_it));
      auto insert_num = nums[i], erase_num = nums[i - k];
      window.insert(insert_num);
      if (insert_num < *mid_it) {
        --mid_it;
      }
      if (erase_num <= *mid_it) {
        ++mid_it;
      }
      window.extract(erase_num);
    }
    result.push_back(get_median(*this, mid_it));
    return result;
  }

 private:
  double oddMedian(It mid_it) { return *mid_it; }

  double evenMedian(It mid_it) {
    return std::midpoint<double>(*std::prev(mid_it), *mid_it);
  }
};
// @lc code=end
