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
    bt(result, 1, n);
    return result;
  }

 private:
  void bt(std::vector<int>& result, int num, int max_num) {
    if (num > max_num) return;
    result.push_back(num);
    bt(result, num * 10, max_num);
    if (num % 10 == 9) return;
    bt(result, num + 1, max_num);
  }
};
// @lc code=end
