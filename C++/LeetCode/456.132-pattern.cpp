/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool find132pattern(std::vector<int>& nums) {
    auto num3 = INT_MIN;
    auto num2_it = nums.end();  // simulates a stack
    for (auto num1_it = nums.rbegin(); num1_it < nums.rend(); ++num1_it) {
      auto num1 = *num1_it;
      if (num1 < num3) return true;
      while (num2_it < nums.end() && num1 > *num2_it) {
        num3 = *num2_it++;
      }
      *(--num2_it) = num1;
    }
    return false;
  }
};
// @lc code=end
