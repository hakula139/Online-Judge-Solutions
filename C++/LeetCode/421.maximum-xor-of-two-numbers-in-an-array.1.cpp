/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int findMaximumXOR(const std::vector<int>& nums) {
    int result = 0;
    for (int i = 31; i >= 0; --i) {
      std::unordered_set<int> prefixes;
      for (auto num : nums) {
        prefixes.insert(num >> i);
      }
      result <<= 1;
      auto expected = result + 1;
      for (auto prefix : prefixes) {
        if (prefixes.contains(prefix ^ expected)) {
          result = expected;
          break;
        }
      }
    }
    return result;
  }
};
// @lc code=end
