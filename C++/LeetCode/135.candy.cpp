/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int candy(const std::vector<int>& ratings) {
    std::vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) {
        candies[i] = candies[i - 1] + 1;
      }
    }
    for (int i = ratings.size() - 1; i > 0; --i) {
      if (ratings[i - 1] > ratings[i]) {
        candies[i - 1] = std::max(candies[i] + 1, candies[i - 1]);
      }
    }
    return std::accumulate(candies.begin(), candies.end(), 0);
  }
};
// @lc code=end
