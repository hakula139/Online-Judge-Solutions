/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <set>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  std::vector<std::string> findAllConcatenatedWordsInADict(
      std::vector<std::string>& words) {
    std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.size() < rhs.size();
    });

    std::unordered_set<size_t> hash_bag;
    std::set<size_t> word_lens;
    std::function<bool(std::string_view)> dfs = [&](std::string_view word) {
      if (word.empty()) return true;
      for (auto len : word_lens) {
        if (len > word.size()) break;
        auto prefix = word.substr(0, len);
        auto hash = std::hash<std::string_view>{}(prefix);
        if (hash_bag.contains(hash) && dfs(word.substr(len))) {
          return true;
        }
      }
      return false;
    };

    std::vector<std::string> result;
    for (std::string_view word : words) {
      if (dfs(word)) {
        result.emplace_back(word);
      } else {
        hash_bag.emplace(std::hash<std::string_view>{}(word));
        word_lens.insert(word.size());
      }
    }
    return result;
  }
};
// @lc code=end
