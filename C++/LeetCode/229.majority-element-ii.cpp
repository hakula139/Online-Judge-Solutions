/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> majorityElement(const std::vector<int>& nums) {
    int x = INT_MIN, y = INT_MIN;
    int count_x = 0, count_y = 0;
    for (auto num : nums) {
      if (num == x) {
        ++count_x;
      } else if (num == y) {
        ++count_y;
      } else if (!count_x) {
        x = num, count_x = 1;
      } else if (!count_y) {
        y = num, count_y = 1;
      } else {
        --count_x, --count_y;
      }
    }

    count_x = 0, count_y = 0;
    for (auto num : nums) {
      if (num == x) {
        ++count_x;
      } else if (num == y) {
        ++count_y;
      }
    }

    std::vector<int> result;
    if (count_x > nums.size() / 3) {
      result.push_back(x);
    }
    if (count_y > nums.size() / 3) {
      result.push_back(y);
    }
    return result;
  }
};
// @lc code=end
