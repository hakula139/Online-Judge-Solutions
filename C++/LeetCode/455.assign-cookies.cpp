/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <algorithm>
#include <vector>

class Solution {
 public:
  int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int result = 0;
    for (auto it = s.begin(); auto greed : g) {
      it = std::find_if(it, s.end(), [greed](int cookie) {
        return cookie >= greed;
      });
      if (it == s.end()) break;
      ++result;
      ++it;
    }
    return result;
  }
};
// @lc code=end
