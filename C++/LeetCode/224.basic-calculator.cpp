/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <functional>
#include <stack>
#include <string>
#include <tuple>

class Solution {
 public:
  using Op = std::function<int(int, int)>;

  int calculate(const std::string& s) {
    std::stack<std::tuple<Op, int>> stack;
    Op op = std::plus<int>();
    int num = 0;

    auto evaluate = [&]() {
      auto& cur = std::get<1>(stack.top());
      cur = op(cur, num);
      num = 0;
    };
    auto push_stack = [&]() {
      stack.emplace(op, 0);
      op = std::plus<int>();
    };
    auto pop_stack = [&]() {
      std::tie(op, num) = stack.top();
      stack.pop();
    };

    push_stack();
    for (auto c : s) {
      if (c == ' ') continue;
      if (std::isdigit(c)) {
        num = num * 10 - '0' + c;
        continue;
      }
      evaluate();
      switch (c) {
        case '+':
          op = std::plus<int>();
          break;
        case '-':
          op = std::minus<int>();
          break;
        case '(':
          push_stack();
          break;
        case ')':
          pop_stack();
          break;
        default:
          // Should not reach here.
          break;
      }
    }
    evaluate();
    pop_stack();
    return num;
  }
};
// @lc code=end
