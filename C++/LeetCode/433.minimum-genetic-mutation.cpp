/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int minMutation(const std::string& start_gene, const std::string& end_gene,
                  const std::vector<std::string>& bank) {
    const std::string kChars = "ACGT";

    std::unordered_map<std::string, bool> visited;
    for (const auto& gene : bank) {
      visited[gene] = false;
    }
    if (!visited.contains(end_gene)) {
      return -1;
    }

    std::queue<std::string> q{{start_gene}};
    int step = 0;
    while (q.size()) {
      ++step;
      for (int i = q.size(); i > 0; --i) {
        auto& gene = q.front();
        for (auto& c : gene) {
          auto base_c = c;
          for (auto new_c : kChars) {
            if (new_c == base_c) continue;
            c = new_c;
            if (gene == end_gene) {
              return step;
            }
            auto it = visited.find(gene);
            if (it != visited.end() && !it->second) {
              it->second = true;
              q.push(gene);
            }
          }
          c = base_c;
        }
        q.pop();
      }
    }
    return -1;
  }
};
// @lc code=end
