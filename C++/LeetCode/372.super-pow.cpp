/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  int superPow(int a, const std::vector<int>& b) {
    if (a == 1) return 1;
    constexpr int k = 1337;
    a %= k;

    std::vector<int> pow_n_map(k, -1);
    std::vector<int> n_pow_map(k);
    int pow = 1, cycle = k;
    for (int n = 0; n < k; ++n) {
      if (pow_n_map[pow] >= 0) {
        cycle = n - pow_n_map[pow];
        break;
      }
      pow_n_map[pow] = n;
      n_pow_map[n] = pow;
      pow = (pow * a) % k;
    }

    int b_val = 0;
    for (auto digit : b) {
      b_val = (b_val * 10 + digit) % cycle;
    }
    if (b_val < pow_n_map[pow]) {
      b_val += cycle;
    }
    return n_pow_map[b_val];
  }
};
// @lc code=end
