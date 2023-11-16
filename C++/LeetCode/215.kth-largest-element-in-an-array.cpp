/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <queue>
#include <vector>

class Solution {
 public:
  int findKthLargest(const std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int i = 0;
    for (; i < k; ++i) {
      q.push(nums[i]);
    }
    for (; i < nums.size(); ++i) {
      if (nums[i] > q.top()) {
        q.push(nums[i]);
        q.pop();
      }
    }
    return q.top();
  }
};
// @lc code=end
