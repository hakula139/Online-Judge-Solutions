/*
 * @lc app=leetcode id=335 lang=cpp
 *
 * [335] Self Crossing
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool isSelfCrossing(std::vector<int>& distance) {
    distance.insert(distance.begin(), 0);  // for edge cases like [1,1,2,1,1]
    for (int i = 3; i < distance.size(); ++i) {
      if (distance[i] >= distance[i - 2] &&
          distance[i - 1] <= distance[i - 3]) {
        return true;
      }
      if (i >= 5 && distance[i - 2] >= distance[i - 4] &&
          distance[i - 2] <= distance[i] + distance[i - 4] &&
          distance[i - 1] >= distance[i - 3] - distance[i - 5] &&
          distance[i - 1] <= distance[i - 3]) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
