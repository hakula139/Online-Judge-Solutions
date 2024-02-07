/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
#include <queue>
#include <utility>
#include <vector>

class Solution {
 public:
  using Pair = std::pair<int, int>;

  std::vector<std::vector<int>> kSmallestPairs(
      const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    std::vector<std::vector<int>> result;
    auto cmp = [&](const Pair& lhs, const Pair& rhs) {
      auto l_sum = nums1[lhs.first] + nums2[lhs.second];
      auto r_sum = nums1[rhs.first] + nums2[rhs.second];
      if (l_sum > r_sum) return true;
      if (l_sum < r_sum) return false;
      return lhs > rhs;
    };
    std::priority_queue<Pair, std::vector<Pair>, decltype(cmp)> q{cmp};
    q.emplace(0, 0);
    while (k-- && q.size()) {
      auto [i1, i2] = q.top();
      q.pop();
      result.push_back({nums1[i1], nums2[i2]});
      if (i1 + 1 < nums1.size()) {
        q.emplace(i1 + 1, i2);
      }
      if (i1 == 0 && i2 + 1 < nums2.size()) {  // to avoid duplicates
        q.emplace(i1, i2 + 1);
      }
    }
    return result;
  }
};
// @lc code=end
