/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
#include <utility>
#include <vector>

class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
      if (nums[i] == val) {
        nums[i] = nums[j--];
      } else {
        ++i;
      }
    }
    return i;
  }
};
// @lc code=end
