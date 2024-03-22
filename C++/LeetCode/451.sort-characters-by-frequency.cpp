/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::string frequencySort(const std::string& s) {
    std::unordered_map<char, int> count;
    for (auto c : s) {
      ++count[c];
    }

    std::vector<std::pair<char, int>> freq{
        std::make_move_iterator(count.begin()),
        std::make_move_iterator(count.end()),
    };
    std::sort(freq.begin(), freq.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.second > rhs.second;
    });

    std::string result;
    for (const auto& [c, n] : freq) {
      result += std::string(n, c);
    }
    return result;
  }
};
// @lc code=end
