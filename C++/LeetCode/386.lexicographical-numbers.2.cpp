/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> result;
    result.reserve(n);
    int num = 1;
    for (int i = 1; i <= n; ++i) {
      result.push_back(num);
      if (num * 10 <= n) {
        num *= 10;
      } else {
        while (num % 10 == 9 || num == n) {
          num /= 10;
        }
        ++num;
      }
    }
    return result;
  }
};
// @lc code=end
