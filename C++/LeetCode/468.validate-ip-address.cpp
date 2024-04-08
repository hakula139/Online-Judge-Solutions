/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

class Solution {
 public:
  using It = std::string_view::const_iterator;

  std::string validIPAddress(const std::string& ip) {
    if (isIPv4(ip)) return "IPv4";
    if (isIPv6(ip)) return "IPv6";
    return "Neither";
  }

 private:
  bool isIPv4(std::string_view ip) {
    auto begin = ip.begin();
    int i = 0;
    for (; i <= 3; ++i) {
      auto [part, it] = nextPart(begin, ip.end(), '.');
      auto len = part.size();
      if (len == 0 || len > 3 || (len > 1 && part[0] == '0')) {
        return false;
      }

      int result = 0;
      for (auto c : part) {
        if (!::isdigit(c)) {
          return false;
        }
        result = result * 10 + c - '0';
      }
      if (result > 255) {
        return false;
      }

      if (it == ip.end()) break;
      begin = it + 1;
    }
    return i == 3;
  }

  bool isIPv6(std::string_view ip) {
    auto begin = ip.begin();
    int i = 0;
    for (; i <= 7; ++i) {
      auto [part, it] = nextPart(begin, ip.end(), ':');
      auto len = part.size();
      if (len == 0 || len > 4) {
        return false;
      }

      if (!std::all_of(part.begin(), part.end(), ::isxdigit)) {
        return false;
      }

      if (it == ip.end()) break;
      begin = it + 1;
    }
    return i == 7;
  }

  std::pair<std::string_view, It> nextPart(It begin, It end, char delim) {
    auto it = std::find(begin, end, delim);
    return {{begin, it}, it};
  }
};
// @lc code=end
