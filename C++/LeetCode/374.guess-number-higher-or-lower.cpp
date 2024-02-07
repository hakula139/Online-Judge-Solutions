/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

/**
 * Forward declaration of guess API.
 * @param num   your guess
 * @return      -1 if num is higher than the picked number
 *              1 if num is lower than the picked number
 *              otherwise return 0
 */
int guess(int num);

// @lc code=start
class Solution {
 public:
  int guessNumber(int n) {
    int begin = 1, end = n;
    while (begin <= end) {
      int mid = begin + (end - begin) / 2;
      auto ret = guess(mid);
      if (ret == 0) {
        return mid;
      } else if (ret < 0) {
        end = mid - 1;
      } else {
        begin = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
