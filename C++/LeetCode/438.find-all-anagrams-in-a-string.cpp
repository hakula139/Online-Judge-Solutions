/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
#include <array>
#include <string>
#include <vector>

constexpr size_t kAlphabetSize = 26;

class Solution {
 public:
  std::vector<int> findAnagrams(const std::string& s, const std::string& p) {
    auto m = s.size(), n = p.size();
    if (m < n) return {};

    std::array<int, kAlphabetSize> p_hash{};
    for (auto c : p) {
      ++p_hash[c - 'a'];
    }

    std::vector<int> result;
    std::array<int, kAlphabetSize> s_hash{};
    for (int i = 0; i < n - 1; ++i) {
      ++s_hash[s[i] - 'a'];
    }
    for (int i = n - 1; i < m; ++i) {
      auto begin = i - n + 1;
      ++s_hash[s[i] - 'a'];
      if (p_hash == s_hash) {
        result.push_back(begin);
      }
      --s_hash[s[begin] - 'a'];
    }
    return result;
  }
};
// @lc code=end
