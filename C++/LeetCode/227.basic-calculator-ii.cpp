/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
 public:
  int calculate(std::string& s) {
    std::stack<int> stack;
    char prev_op = '+';
    int num = 0;
    s += '+';

    for (auto c : s) {
      if (c == ' ') continue;
      if (std::isdigit(c)) {
        num = num * 10 - '0' + c;
        continue;
      }
      switch (prev_op) {
        case '+':
          stack.push(num);
          break;
        case '-':
          stack.push(-num);
          break;
        case '*':
          stack.top() *= num;
          break;
        case '/':
          stack.top() /= num;
          break;
        default:
          // Should not reach here.
          break;
      }
      prev_op = c;
      num = 0;
    }
    while (stack.size()) {
      num += stack.top();
      stack.pop();
    }
    return num;
  }
};
// @lc code=end
