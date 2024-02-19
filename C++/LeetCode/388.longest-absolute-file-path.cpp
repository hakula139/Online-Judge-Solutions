/*
 * @lc app=leetcode id=388 lang=cpp
 *
 * [388] Longest Absolute File Path
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <string>

class Solution {
 public:
  int lengthLongestPath(const std::string& input) {
    int max_len = 0;
    std::stack<int> parent_stack{{0, 0}};
    for (auto it = input.begin(); it < input.end(); ++it) {
      int level = 0;
      for (; it < input.end() && *it == '\t'; ++it, ++level) {
      }

      int len = 0;
      bool is_file = false;
      for (; it < input.end() && *it != '\n'; ++it, ++len) {
        if (*it == '.') {
          is_file = true;
        }
      }

      while (parent_stack.size() > level + 1) {
        parent_stack.pop();
      }
      if (is_file) {
        max_len = std::max(parent_stack.top() + len, max_len);
      } else {
        parent_stack.push(parent_stack.top() + len + 1);
      }
    }
    return max_len;
  }
};
// @lc code=end
