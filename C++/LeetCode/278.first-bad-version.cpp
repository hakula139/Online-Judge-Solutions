/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

bool isBadVersion(int version);

// @lc code=start
class Solution {
 public:
  int firstBadVersion(int n) {
    int begin = 1, end = n;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (isBadVersion(mid)) {
        end = mid;
      } else {
        begin = mid + 1;
      }
    }
    return begin;
  }
};
// @lc code=end
