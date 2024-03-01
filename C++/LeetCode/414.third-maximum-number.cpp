/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <set>
#include <vector>

class Solution {
 public:
  int thirdMax(const std::vector<int>& nums) {
    std::set<int> set;
    for (auto num : nums) {
      set.insert(num);
      if (set.size() > 3) {
        set.erase(set.begin());
      }
    }
    return set.size() == 3 ? *set.begin() : *set.rbegin();
  }
};
// @lc code=end
