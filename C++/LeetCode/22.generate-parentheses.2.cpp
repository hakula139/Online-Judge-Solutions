/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> generateParenthesis(int n) {
    generateParenthesis(n, 0);
    return result_;
  }

 private:
  void generateParenthesis(int open, int close) {
    if (!open && !close) {
      result_.push_back(buf_);
      return;
    }
    if (open > 0) {
      buf_ += '(';
      generateParenthesis(open - 1, close + 1);
      buf_.pop_back();
    }
    if (close > 0) {
      buf_ += ')';
      generateParenthesis(open, close - 1);
      buf_.pop_back();
    }
  }

  std::vector<std::string> result_;
  std::string buf_;
};
// @lc code=end
