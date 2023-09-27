/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    std::unordered_map<char, int> count;
    for (auto c : t) {
      --count[c];
    }

    int min_width = INT_MAX, min_begin = s.size();
    int match_count = 0;
    auto begin_it = s.begin(), end_it = s.begin();
    for (; end_it < s.end(); ++end_it) {
      if (!count.contains(*end_it)) continue;
      if (++count[*end_it] == 0) {
        ++match_count;
      }
      if (match_count < count.size()) continue;
      for (; begin_it <= end_it; ++begin_it) {
        auto count_it = count.find(*begin_it);
        if (count_it != count.end()) {
          if (!count_it->second) break;
          --count_it->second;
        }
      }
      int width = end_it - begin_it + 1;
      if (width < min_width) {
        min_width = width;
        min_begin = begin_it - s.begin();
      }
    }
    return s.substr(min_begin, min_width);
  }
};
// @lc code=end
