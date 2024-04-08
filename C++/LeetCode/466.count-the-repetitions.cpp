/*
 * @lc app=leetcode id=466 lang=cpp
 *
 * [466] Count The Repetitions
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int getMaxRepetitions(
      const std::string& s1, int n1, const std::string& s2, int n2) {
    std::vector n_repeats{0};
    std::unordered_map<int, int> next_i2_map{{0, 0}};
    for (int k = 1, i2 = 0; k <= n1; ++k) {
      auto n_repeat = n_repeats.back();
      for (auto c1 : s1) {
        if (c1 != s2[i2]) continue;
        if (++i2 == s2.size()) {
          i2 = 0;
          ++n_repeat;
        }
      }
      n_repeats.push_back(n_repeat);

      auto it = next_i2_map.find(i2);
      if (it == next_i2_map.end()) {
        next_i2_map[i2] = k;
        continue;
      }

      auto begin = it->second;
      auto n_prefix = n_repeats[begin];
      auto n_pattern = (n1 - begin) / (k - begin) * (n_repeat - n_prefix);
      auto n_suffix = n_repeats[begin + (n1 - begin) % (k - begin)] - n_prefix;
      return (n_prefix + n_pattern + n_suffix) / n2;
    }
    return n_repeats.back() / n2;
  }
};
// @lc code=end
