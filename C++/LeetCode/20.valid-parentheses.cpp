/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
 public:
  bool isValid(const std::string& s) {
    std::stack<char> stack;
    for (auto c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          stack.push(c);
          break;
        case ')':
          if (stack.empty() || stack.top() != '(') {
            return false;
          }
          stack.pop();
          break;
        case ']':
          if (stack.empty() || stack.top() != '[') {
            return false;
          }
          stack.pop();
          break;
        case '}':
          if (stack.empty() || stack.top() != '{') {
            return false;
          }
          stack.pop();
          break;
        default:
          break;
      }
    }
    return stack.empty();
  }
};
// @lc code=end
