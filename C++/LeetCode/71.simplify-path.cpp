/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(const std::string& path) {
    std::vector<std::string> parts;
    for (auto it = path.begin() + 1; it < path.end();) {
      auto next_sep = std::find(it, path.end(), '/');
      auto part = path.substr(it - path.begin(), next_sep - it);
      if (part == "..") {
        if (parts.size()) {
          parts.pop_back();
        }
      } else if (part.size() && part != ".") {
        parts.emplace_back(std::move(part));
      }
      it = next_sep + 1;
    }

    std::string result;
    for (const auto& part : parts) {
      result += '/' + part;
    }
    return result.size() ? result : "/";
  }
};
// @lc code=end
