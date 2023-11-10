/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(const std::string& s) {
    constexpr int kLen = 10;
    constexpr auto kMask = (1U << (kLen << 1)) - 1;
    const std::unordered_map<char, int> codes{
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3},
    };
    auto next_hash = [&](int i) {
      static auto key = 0U;
      key = ((key << 2) | codes.at(s[i])) & kMask;
      return key;
    };

    std::vector<std::string> result;
    std::unordered_map<uint32_t, int> count;
    for (int i = 0; i < s.size() && i < kLen - 1; ++i) {
      next_hash(i);
    }
    for (int i = kLen - 1; i < s.size(); ++i) {
      auto key = next_hash(i);
      if (++count[key] == 2) {
        result.emplace_back(s.substr(i - kLen + 1, kLen));
      }
    }
    return result;
  }
};
// @lc code=end
