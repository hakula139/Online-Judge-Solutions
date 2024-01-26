/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findItinerary(
      std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (auto&& ticket : tickets) {
      graph[ticket[0]].emplace_back(std::move(ticket[1]));
    }
    for (auto&& [_, dests] : graph) {
      std::sort(dests.rbegin(), dests.rend());
    }

    std::vector<std::string> path;
    std::string start = "JFK";
    std::function<void(std::string&)> dfs = [&](std::string& node) {
      while (graph[node].size()) {
        auto next = std::move(graph[node].back());
        graph[node].pop_back();
        dfs(next);
      }
      path.emplace_back(std::move(node));
    };
    dfs(start);
    std::reverse(path.begin(), path.end());
    return path;
  }
};
// @lc code=end
