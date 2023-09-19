/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int jump(const std::vector<int>& nums) {
    if (nums.size() == 1) return 0;

    int jumps = 1;
    int end = 0, max_end = nums[0];
    for (int i = 0; i <= end; ++i) {
      int cur_end = i + nums[i];
      if (cur_end >= nums.size() - 1) break;
      max_end = std::max(cur_end, max_end);
      if (i == end) {
        ++jumps;
        end = max_end;
      }
    }
    return jumps;
  }
};
// @lc code=end
