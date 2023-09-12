/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    if (x % 10 == 0) return false;

    auto reversed_x = 0ll;
    for (auto r = x; r > 0; r /= 10) {
      reversed_x = reversed_x * 10 + r % 10;
    }
    return x == reversed_x;
  }
};
// @lc code=end
