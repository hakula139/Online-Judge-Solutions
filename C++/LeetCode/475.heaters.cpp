/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
    auto m = houses.size(), n = heaters.size();
    std::sort(houses.begin(), houses.end());
    std::sort(heaters.begin(), heaters.end());
    std::vector result(houses.size(), INT_MAX);

    for (int i = 0, j = 0; i < m && j < n;) {
      if (houses[i] <= heaters[j]) {
        result[i] = heaters[j] - houses[i];
        ++i;
      } else {
        ++j;
      }
    }

    for (int i = m - 1, j = n - 1; i >= 0 && j >= 0;) {
      if (houses[i] >= heaters[j]) {
        result[i] = std::min(houses[i] - heaters[j], result[i]);
        --i;
      } else {
        --j;
      }
    }

    return *std::max_element(result.begin(), result.end());
  }
};
// @lc code=end
