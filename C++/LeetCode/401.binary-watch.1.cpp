/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> readBinaryWatch(int turned_on) {
    std::vector<std::string> result;
    char time[6];  // "hh:mm\0"
    for (int i = turned_on; i >= 0; --i) {
      auto hours = getNumbers(i, 11);
      if (hours.empty()) continue;
      auto minutes = getNumbers(turned_on - i, 59);
      if (minutes.empty()) break;
      for (auto hour : hours) {
        for (auto minute : minutes) {
          std::snprintf(time, sizeof(time), "%d:%02d", hour, minute);
          result.emplace_back(time);
        }
      }
    }
    return result;
  }

 private:
  std::vector<int> getNumbers(int count, int limit) {
    if (count < 0 || (1 << count) - 1 > limit) return {};
    std::vector<int> result;
    int num = 0;
    bt(result, num, 1, count, limit);
    return result;
  }

  void bt(std::vector<int>& result, int& num, int bit, int count, int limit) {
    if (num > limit) return;
    if (count == 0) {
      result.push_back(num);
      return;
    }
    if (bit > limit) return;
    bt(result, num, bit << 1, count, limit);
    num |= bit;
    bt(result, num, bit << 1, count - 1, limit);
    num &= ~bit;
  }
};
// @lc code=end
