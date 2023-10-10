/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>

class Solution {
 public:
  int largestRectangleArea(std::vector<int>& heights) {
    int result = 0;
    std::stack<int> stack;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i) {
      while (stack.size() && heights[i] < heights[stack.top()]) {
        int h = heights[stack.top()];
        stack.pop();
        int j = stack.size() ? stack.top() : -1;
        int w = i - j - 1;
        result = std::max(h * w, result);
      }
      stack.push(i);
    }
    return result;
  }
};
// @lc code=end
