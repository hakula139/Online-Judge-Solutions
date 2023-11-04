/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> stack;
    const std::unordered_map<std::string, std::function<int(int, int)>> ops{
        {"+", std::plus<int>()},
        {"-", std::minus<int>()},
        {"*", std::multiplies<int>()},
        {"/", std::divides<int>()},
    };
    for (const auto& token : tokens) {
      auto it = ops.find(token);
      if (it == ops.end()) {
        stack.push(std::stoi(token));
      } else {
        auto num2 = stack.top();
        stack.pop();
        auto num1 = stack.top();
        stack.pop();
        stack.push(it->second(num1, num2));
      }
    }
    return stack.top();
  }
};
// @lc code=end
