/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int hIndex(const std::vector<int>& citations) {
    int n = citations.size();
    int begin = 0, end = n;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      int count = n - mid;
      if (citations[mid] == count) {
        return count;
      } else if (citations[mid] < count) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return n - begin;
  }
};
// @lc code=end
