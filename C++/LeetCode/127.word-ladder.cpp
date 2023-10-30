/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
 public:
  int ladderLength(const std::string& begin_word, const std::string& end_word,
                   std::vector<std::string>& word_list) {
    auto it = std::find(word_list.begin(), word_list.end(), end_word);
    if (it == word_list.end()) return 0;
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

    std::queue<int> q{{n}};  // begin_word
    std::vector<bool> visited(n);
    for (int step = 1; q.size(); ++step) {
      for (int i = q.size(); i > 0; --i) {
        auto last = q.front();
        if (last == end) return step;

        auto&& word = word_list[last];
        for (auto&& c : word) {
          std::swap(c, wildcard);
          auto it = dict.find(word);
          std::swap(c, wildcard);
          if (it == dict.end()) continue;
          for (auto node : it->second) {
            if (visited[node]) continue;
            visited[node] = true;
            q.push(node);
          }
        }
        q.pop();
      }
    }
    return 0;
  }
};
// @lc code=end
