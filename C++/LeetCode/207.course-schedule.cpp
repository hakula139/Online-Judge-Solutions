/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  bool canFinish(int num_courses,
                 const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(num_courses);
    for (const auto& edge : prerequisites) {
      graph[edge[0]].push_back(edge[1]);
    }
    std::vector<bool> g_visited(num_courses);
    std::vector<bool> visited(num_courses);
    for (int i = 0; i < num_courses; ++i) {
      if (!dfs(graph, g_visited, visited, i)) {
        return false;
      }
    }
    return true;
  }

 private:
  bool dfs(const std::vector<std::vector<int>>& graph,
           std::vector<bool>& g_visited, std::vector<bool>& visited,
           int course) {
    if (g_visited[course]) return true;
    if (visited[course]) return false;
    visited[course] = true;
    for (auto pre : graph[course]) {
      if (!dfs(graph, g_visited, visited, pre)) {
        return false;
      }
    }
    visited[course] = false;
    g_visited[course] = true;
    return true;
  }
};
// @lc code=end
