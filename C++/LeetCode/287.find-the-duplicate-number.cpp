/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int findDuplicate(const std::vector<int>& nums) {
    int fast = 0, slow = 0;
    do {
      fast = nums[nums[fast]];
      slow = nums[slow];
    } while (fast != slow);
    slow = 0;
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
};
// @lc code=end
