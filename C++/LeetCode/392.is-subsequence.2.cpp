/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  // Follow up
  bool isSubsequence(const std::string& s, const std::string& t) {
    std::vector<std::vector<int>> t_indices(kAlphabetSize);
    for (int i = 0; i < t.size(); ++i) {
      t_indices[t[i] - 'a'].push_back(i);
    }

    int prev_i = -1;
    for (auto c : s) {
      const auto& indices = t_indices[c - 'a'];
      auto it = std::upper_bound(indices.begin(), indices.end(), prev_i);
      if (it == indices.end()) return false;
      prev_i = *it;
    }
    return true;
  }
};
// @lc code=end
