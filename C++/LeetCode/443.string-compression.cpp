/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int compress(std::vector<char>& chars) {
    auto out_it = chars.begin() + 1;
    int count = 1;
    auto print_count = [&]() {
      if (count == 1) return;
      auto begin_it = out_it;
      while (count) {
        *out_it++ = '0' + count % 10;
        count /= 10;
      }
      std::reverse(begin_it, out_it);
    };

    for (auto it = out_it; it < chars.end(); ++it) {
      if (*it == *std::prev(it)) {
        ++count;
      } else {
        print_count();
        *out_it++ = *it;
        count = 1;
      }
    }
    print_count();
    return out_it - chars.begin();
  }
};
// @lc code=end
