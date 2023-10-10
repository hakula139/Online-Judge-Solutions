/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
    int result = 0;
    auto n = matrix[0].size();
    std::vector<int> heights(n + 1);
    for (const auto& row : matrix) {
      std::stack<int> stack;
      for (int i = 0; i < n; ++i) {
        heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
      }
      for (int i = 0; i <= n; ++i) {
        while (stack.size() && heights[i] < heights[stack.top()]) {
          int h = heights[stack.top()];
          stack.pop();
          int j = stack.size() ? stack.top() : -1;
          int w = i - j - 1;
          result = std::max(h * w, result);
        }
        stack.push(i);
      }
    }
    return result;
  }
};
// @lc code=end
