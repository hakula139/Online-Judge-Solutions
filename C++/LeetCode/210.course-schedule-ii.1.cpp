/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <vector>

class Solution {
 public:
  std::vector<int> findOrder(
      int num_courses, const std::vector<std::vector<int>>& prerequisites) {
    std::vector<std::vector<int>> graph(num_courses);
    for (const auto& edge : prerequisites) {
      graph[edge[0]].push_back(edge[1]);
    }
    std::vector<int> result;
    result.reserve(num_courses);
    std::vector<bool> g_visited(num_courses);
    std::vector<bool> visited(num_courses);
    for (int i = 0; i < num_courses; ++i) {
      if (!dfs(graph, result, g_visited, visited, i)) {
        result.clear();
        break;
      }
    }
    return result;
  }

 private:
  bool dfs(const std::vector<std::vector<int>>& graph, std::vector<int>& path,
           std::vector<bool>& g_visited, std::vector<bool>& visited,
           int course) {
    if (g_visited[course]) return true;
    if (visited[course]) return false;
    visited[course] = true;
    for (auto prev : graph[course]) {
      if (!dfs(graph, path, g_visited, visited, prev)) {
        return false;
      }
    }
    visited[course] = false;
    g_visited[course] = true;
    path.push_back(course);
    return true;
  }
};
// @lc code=end
