#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    result_.clear();
    Backtrack("", n, 0);
    return result_;
  }

 private:
  vector<string> result_;

  void Backtrack(const string& cur, int open, int close) {
    if (!open && !close) {
      result_.push_back(cur);
      return;
    }
    if (open) Backtrack(cur + '(', open - 1, close + 1);
    if (close) Backtrack(cur + ')', open, close - 1);
  }
};
