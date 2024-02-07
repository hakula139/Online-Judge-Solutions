/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
 public:
  int wiggleMaxLength(const std::vector<int>& nums) {
    int len = 1, prev = nums[0], prev_dir = 0;
    for (auto num : nums) {
      if (prev == num) continue;
      auto dir = compare(prev, num);
      if (prev_dir != dir) {
        ++len;
        prev_dir = dir;
      }
      prev = num;
    }
    return len;
  }

 private:
  int compare(int lhs, int rhs) {
    if (lhs < rhs) return -1;
    if (lhs > rhs) return 1;
    return 0;
  }
};
// @lc code=end
