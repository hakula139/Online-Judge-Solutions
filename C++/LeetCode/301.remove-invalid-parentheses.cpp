/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
#include <queue>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::string> removeInvalidParentheses(const std::string& s) {
    std::vector<std::string> result;
    std::queue<std::pair<std::string, int>> q{{{s, 0}}};
    while (result.empty()) {
      for (int i = q.size(); i > 0; --i) {
        auto&& [cur, j] = q.front();
        if (isValid(cur)) {
          result.emplace_back(std::move(cur));
        } else {
          for (; j < cur.size(); ++j) {
            if ((cur[j] == '(' || cur[j] == ')') &&
                (j == 0 || cur[j] != cur[j - 1])) {
              q.emplace(cur.substr(0, j) + cur.substr(j + 1), j);
            }
          }
        }
        q.pop();
      }
    }
    return result;
  }

 private:
  bool isValid(const std::string& s) {
    int count = 0;
    for (auto c : s) {
      if (c == '(') {
        ++count;
      } else if (c == ')') {
        if (--count < 0) {
          return false;
        }
      }
    }
    return count == 0;
  }
};
// @lc code=end
