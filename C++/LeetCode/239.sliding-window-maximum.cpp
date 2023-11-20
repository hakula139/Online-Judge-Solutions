/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <deque>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::deque<int> q;
    auto push_q = [&](int i) {
      while (q.size() && nums[q.back()] <= nums[i]) {
        q.pop_back();
      }
      q.push_back(i);
    };

    std::vector<int> result;
    for (int i = 0; i < k - 1; ++i) {
      push_q(i);
    }
    for (int i = k - 1; i < nums.size(); ++i) {
      if (q.size() && q.front() <= i - k) {
        q.pop_front();
      }
      push_q(i);
      result.push_back(nums[q.front()]);
    }
    return result;
  }
};
// @lc code=end
