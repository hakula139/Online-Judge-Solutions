/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <string>

class Solution {
 public:
  int longestValidParentheses(const std::string& s) {
    int result = 0;
    std::stack<int> stack{{-1}};
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stack.push(i);
      } else {
        stack.pop();
        if (stack.empty()) {
          stack.push(i);
        }
        result = std::max(i - stack.top(), result);
      }
    }
    return result;
  }
};
// @lc code=end
