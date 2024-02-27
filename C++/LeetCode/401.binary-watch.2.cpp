/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
#include <bit>
#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> readBinaryWatch(int turned_on) {
    std::vector<std::string> result;
    char buf[6];  // "hh:mm\0"
    for (uint8_t hour = 0; hour <= 11; ++hour) {
      for (uint8_t minute = 0; minute <= 59; ++minute) {
        if (std::popcount(hour) + std::popcount(minute) == turned_on) {
          std::snprintf(buf, sizeof(buf), "%d:%02d", hour, minute);
          result.emplace_back(buf);
        }
      }
    }
    return result;
  }
};
// @lc code=end
