/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start
#include <queue>
#include <vector>

class Solution {
 public:
  int nthSuperUglyNumber(int n, const std::vector<int>& primes) {
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> q;
    q.push(1);
    for (int i = 1; i < n; ++i) {
      auto num = q.top();
      q.pop();
      for (auto prime : primes) {
        q.push(num * prime);
        if (num % prime == 0) break;
      }
    }
    return q.top();
  }
};
// @lc code=end
