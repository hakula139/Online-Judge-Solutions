/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <stack>
#include <vector>

class Solution {
 public:
  std::vector<int> findOrder(
      int num_courses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(num_courses);
    std::vector<int> degrees(num_courses);
    for (const auto& edge : prerequisites) {
      graph[edge[1]].push_back(edge[0]);
      ++degrees[edge[0]];
    }
    std::vector<int> result;
    result.reserve(num_courses);
    std::stack<int> start_nodes;
    for (int i = 0; i < num_courses; ++i) {
      if (degrees[i] == 0) {
        start_nodes.push(i);
      }
    }
    while (start_nodes.size()) {
      auto course = start_nodes.top();
      result.push_back(course);
      start_nodes.pop();
      for (auto next : graph[course]) {
        if (--degrees[next] == 0) {
          start_nodes.push(next);
        }
      }
      graph[course].clear();
    }
    if (result.size() < num_courses) {
      result.clear();
    }
    return result;
  }
};
// @lc code=end
