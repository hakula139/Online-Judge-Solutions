/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int canCompleteCircuit(
      const std::vector<int>& gas, const std::vector<int>& cost) {
    int total = 0;
    for (int i = 0; i < gas.size(); ++i) {
      total += gas[i] - cost[i];
    }
    if (total < 0) return -1;

    int start = 0, tank = 0;
    for (int i = 0; i < gas.size(); ++i) {
      tank += gas[i] - cost[i];
      if (tank < 0) {
        start = i + 1, tank = 0;
      }
    }
    return start;
  }
};
// @lc code=end
