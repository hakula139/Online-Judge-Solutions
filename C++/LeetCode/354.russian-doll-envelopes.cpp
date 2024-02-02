/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include <algorithm>
#include <vector>

struct Envelope {
  int width;
  int height;

  bool operator<(const Envelope& rhs) const {
    return width < rhs.width && height < rhs.height;
  }
};

class Solution {
 public:
  int maxEnvelopes(const std::vector<std::vector<int>>& envelopes) {
    std::vector<Envelope> sorted_envelopes;
    for (const auto& e : envelopes) {
      sorted_envelopes.emplace_back(e[0], e[1]);
    }
    // Sort widths in ascending order, and then heights in descending order.
    std::sort(
        sorted_envelopes.begin(), sorted_envelopes.end(),
        [](const Envelope& lhs, const Envelope& rhs) {
          if (lhs.width < rhs.width) return true;
          if (lhs.width > rhs.width) return false;
          return lhs.height > rhs.height;
        });

    std::vector<Envelope> result;
    for (auto&& e : sorted_envelopes) {
      auto it = std::lower_bound(result.begin(), result.end(), e);
      if (it == result.end()) {
        result.emplace_back(std::move(e));
      } else {
        *it = std::move(e);
      }
    }
    return result.size();
  }
};
// @lc code=end
