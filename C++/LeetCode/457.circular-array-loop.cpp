/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool circularArrayLoop(std::vector<int>& nums) {
    int n = nums.size();
    auto next = [&](int i) {
      auto j = (i + nums[i]) % n;
      return j >= 0 ? j : j + n;
    };
    auto advance = [&](int& i) { return i = next(i); };
    auto is_same_dir = [&](int i, int j) {
      return nums[i] > 0 && nums[j] > 0 || nums[i] < 0 && nums[j] < 0;
    };

    for (int i = 0; i < n; ++i) {
      if (nums[i] == 0) continue;
      auto fast = i, slow = i;
      while (is_same_dir(advance(fast), slow) &&
             is_same_dir(advance(fast), advance(slow))) {
        if (fast == slow) {
          if (next(slow) == slow) break;  // self loop
          return true;
        }
      }
      for (int j = i; is_same_dir(j, next(j));) {
        auto next_j = next(j);
        nums[j] = 0;
        j = next_j;
      }
    }
    return false;
  }
};
// @lc code=end
