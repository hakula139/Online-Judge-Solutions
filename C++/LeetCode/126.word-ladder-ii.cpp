/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

#include <iostream>

// @lc code=start
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> findLadders(
      const std::string& begin_word, const std::string& end_word,
      std::vector<std::string>& word_list) {
    auto it = std::find(word_list.begin(), word_list.end(), end_word);
    if (it == word_list.end()) return {};
    int end = it - word_list.begin();

    int n = word_list.size();
    word_list.emplace_back(begin_word);
    std::unordered_map<std::string, std::vector<int>> dict;
    char wildcard = '*';
    for (int i = 0; i < n; ++i) {
      auto&& word = word_list[i];
      for (auto&& c : word) {
        std::swap(c, wildcard);
        dict[word].push_back(i);
        std::swap(c, wildcard);
      }
    }

    std::vector<std::vector<std::string>> result;
    std::queue<int> q{{n}};  // begin_word
    std::vector<std::vector<int>> parents(n);
    std::vector<int> visited(n, INT_MAX);
    for (int step = 1; q.size(); ++step) {
      for (int i = q.size(); i > 0; --i) {
        auto last = q.front();
        if (last == end) {
          std::vector<std::string> path{end_word};
          getResult(result, path, parents, word_list, end);
          return result;
        }

        auto&& word = word_list[last];
        for (auto&& c : word) {
          std::swap(c, wildcard);
          auto it = dict.find(word);
          std::swap(c, wildcard);
          if (it == dict.end()) continue;
          for (auto node : it->second) {
            if (visited[node] < step) {
              continue;  // A shorter path exists, so this path is pruned.
            }
            parents[node].push_back(last);
            if (parents[node].size() > 1) {
              continue;  // No need to search after the same node again.
            }
            visited[node] = step;
            q.push(node);
          }
        }
        q.pop();
      }
    }
    return result;
  }

 private:
  void getResult(
      std::vector<std::vector<std::string>>& result,
      std::vector<std::string>& path,
      const std::vector<std::vector<int>>& parents,
      const std::vector<std::string>& word_list, int node) {
    if (node == word_list.size() - 1) {
      result.emplace_back(path);
      std::reverse(result.back().begin(), result.back().end());
      return;
    }

    for (auto prev : parents[node]) {
      path.emplace_back(word_list[prev]);
      getResult(result, path, parents, word_list, prev);
      path.pop_back();
    }
  }
};
// @lc code=end

int main() {
  Solution sol;
  auto begin_word = "hit";
  auto end_word = "cog";
  std::vector<std::string> word_list{
      "hot", "dot", "dog", "lot", "log", "cog",
  };
  auto result = sol.findLadders(begin_word, end_word, word_list);
  for (const auto& ladder : result) {
    for (const auto& word : ladder) {
      std::cout << word << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
