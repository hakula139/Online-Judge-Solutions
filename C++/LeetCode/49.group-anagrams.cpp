/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> groupAnagrams(
      const std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> hash_idx;
    for (const auto& s : strs) {
      std::string hash(26, 0);
      for (auto c : s) {
        ++hash[c - 'a'];
      }
      hash_idx[hash].push_back(s);
    }
    result.reserve(hash_idx.size());
    for (auto&& [hash, v] : hash_idx) {
      result.emplace_back(std::move(v));
    }
    return result;
  }
};
// @lc code=end
