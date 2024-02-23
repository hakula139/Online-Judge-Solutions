/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <stack>
#include <string>
#include <utility>

class Solution {
 public:
  std::string decodeString(const std::string& s) {
    std::stack<std::pair<int, std::string>> stack;
    stack.emplace();
    for (auto c : s) {
      auto& [count, buf] = stack.top();
      if (std::isdigit(c)) {
        count = count * 10 + c - '0';
      } else if (c == '[') {
        stack.emplace();
      } else if (c == ']') {
        auto sub_s = std::move(buf);
        stack.pop();
        auto& [count, buf] = stack.top();
        buf.reserve(buf.size() + count * sub_s.size());
        for (; count; --count) {
          buf += sub_s;
        }
      } else {
        buf += c;
      }
    }
    return stack.top().second;
  }
};
// @lc code=end
