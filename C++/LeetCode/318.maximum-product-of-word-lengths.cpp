/*
 * @lc app=leetcode id=318 lang=cpp
 *
 * [318] Maximum Product of Word Lengths
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

class Solution {
 public:
  int maxProduct(const std::vector<std::string>& words) {
    size_t result = 0;
    std::vector<uint32_t> bitsets(words.size());
    for (int i = 0; i < words.size(); ++i) {
      for (auto c : words[i]) {
        bitsets[i] |= 1 << (c - 'a');
      }
      for (int j = 0; j < i; ++j) {
        if (!(bitsets[i] & bitsets[j])) {
          result = std::max(words[i].size() * words[j].size(), result);
        }
      }
    }
    return result;
  }
};
// @lc code=end
