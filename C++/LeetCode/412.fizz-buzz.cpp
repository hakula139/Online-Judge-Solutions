/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> result(n);
    for (int i = 2; i < n; i += 3) {
      result[i] = "Fizz";
    }
    for (int i = 4; i < n; i += 5) {
      result[i] += "Buzz";
    }
    for (int i = 0; i < n; ++i) {
      if (result[i].empty()) {
        result[i] = std::to_string(i + 1);
      }
    }
    return result;
  }
};
// @lc code=end
