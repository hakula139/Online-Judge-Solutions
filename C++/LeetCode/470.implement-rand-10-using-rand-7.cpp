/*
 * @lc app=leetcode id=470 lang=cpp
 *
 * [470] Implement Rand10() Using Rand7()
 */

/**
 * @return a random integer in the range 1 to 7
 */
int rand7();

// @lc code=start
class Solution {
 public:
  /**
   *    E(x) = 2 + (9 / 49 * E(x))
   * => E(x) = 2.45
   */
  int rand10() {
    while (true) {
      auto rand1 = rand7(), rand2 = rand7();    // [1, 7]
      auto rand = (rand1 - 1) * 7 + rand2 - 1;  // [0, 48]
      if (rand >= 40) continue;                 // [0, 39]
      return rand % 10 + 1;                     // [1, 10]
    }
  }
};
// @lc code=end
