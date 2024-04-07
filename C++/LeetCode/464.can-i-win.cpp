/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
#include <vector>

enum class Result {
  kUnknown = 0,
  kWin = 1,
  kLose = -1,
};

class Solution {
 public:
  bool canIWin(int n, int desired_total) {
    if (n >= desired_total) {
      return true;
    }
    auto sum = n * (n + 1) / 2;
    if (sum < desired_total) {
      return false;
    }
    if (sum == desired_total) {
      return n % 2 == 1;
    }

    auto nums = (1U << n) - 1;
    mem_ = std::vector(nums + 1, Result::kUnknown);
    return canWin(nums, n, desired_total) == Result::kWin;
  }

 private:
  Result canWin(uint32_t nums, int n, int target) {
    auto& result = mem_[nums];
    if (result != Result::kUnknown) {
      return result;
    }

    auto i = n;
    auto mask = 1U << (n - 1);
    for (; i >= 1 && !(nums & mask); --i, mask >>= 1) {
    }
    if (i >= target) {
      result = Result::kWin;
      return result;
    }

    for (; i >= 1; --i, mask >>= 1) {
      if (!(nums & mask)) continue;
      if (canWin(nums ^ mask, n, target - i) == Result::kLose) {
        result = Result::kWin;
        return result;
      }
    }
    result = Result::kLose;
    return result;
  }

  std::vector<Result> mem_;
};
// @lc code=end
