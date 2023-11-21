/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 */

// @lc code=start
#include <functional>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  using Op = std::function<int(int, int)>;
  std::vector<int> diffWaysToCompute(std::string& expression) {
    std::vector<std::pair<Op, int>> parsed_expr;
    Op op = std::plus<int>();
    int num = 0;
    expression += '+';

    for (auto c : expression) {
      if (std::isdigit(c)) {
        num = num * 10 - '0' + c;
        continue;
      }
      parsed_expr.emplace_back(op, num);
      num = 0;
      switch (c) {
        case '+':
          op = std::plus<int>();
          break;
        case '-':
          op = std::minus<int>();
          break;
        case '*':
          op = std::multiplies<int>();
          break;
        default:
          // Should not reach here.
          break;
      }
    }

    auto n = parsed_expr.size();
    std::vector dp{n + 1, std::vector{n + 1, std::vector<int>{}}};
    for (int i = 0; i < n; ++i) {
      dp[1][i].push_back(parsed_expr[i].second);
    }
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i < n; ++i) {
        for (int j = 1; j < len; ++j) {
          for (auto left : dp[j][i]) {
            for (auto right : dp[len - j][i + j]) {
              const auto& op = parsed_expr[i + j].first;
              dp[len][i].push_back(op(left, right));
            }
          }
        }
      }
    }
    return dp[n][0];
  }
};
// @lc code=end
