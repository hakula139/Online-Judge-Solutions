/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> addOperators(const std::string& num, int target) {
    std::vector<std::string> result;
    std::string expr;
    bt(result, expr, num, 0, 0, 0, target);
    return result;
  }

 private:
  void bt(std::vector<std::string>& result, std::string& expr,
          const std::string& s, int i, int64_t expr_result, int64_t prev_num,
          int64_t target) {
    if (i == s.size()) {
      if (expr_result == target) {
        result.push_back(expr);
      }
      return;
    }

    int64_t cur_num = 0;
    int op_i = expr.size();
    if (op_i) expr += '+';
    int j_end = s[i] == '0' ? i + 1 : s.size();
    for (int j = i + 1; j <= j_end; ++j) {
      expr += s[j - 1];
      cur_num = cur_num * 10 + s[j - 1] - '0';
      if (op_i) {
        expr[op_i] = '+';
        bt(result, expr, s, j, expr_result + cur_num, cur_num, target);
        expr[op_i] = '-';
        bt(result, expr, s, j, expr_result - cur_num, -cur_num, target);
        expr[op_i] = '*';
        bt(result, expr, s, j, expr_result - prev_num + prev_num * cur_num,
           prev_num * cur_num, target);
      } else {
        bt(result, expr, s, j, cur_num, cur_num, target);
      }
    }
    expr.erase(op_i);
  }
};
// @lc code=end
