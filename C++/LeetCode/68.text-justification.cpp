/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::string> fullJustify(std::vector<std::string>& words,
                                       int max_width) {
    std::vector<std::string> result;
    std::vector<std::string> line;
    int cur_width = 0;

    auto print_line = [&](bool is_last_line = false) {
      std::string buf;
      buf.reserve(max_width);
      int rest_space_cnt = max_width - cur_width;
      for (int i = 0; i < line.size(); ++i) {
        int space_cnt = rest_space_cnt > 0 ? 1 : 0;
        if (!is_last_line) {
          int n = line.size() - i - 1;
          space_cnt = n > 0 ? (rest_space_cnt + n - 1) / n : 0;
        }
        buf += line[i];
        buf.append(space_cnt, ' ');
        rest_space_cnt -= space_cnt;
      }
      buf.append(rest_space_cnt, ' ');
      result.emplace_back(std::move(buf));
    };

    for (auto&& word : words) {
      if (cur_width + word.size() + line.size() <= max_width) {
        cur_width += word.size();
        line.emplace_back(std::move(word));
      } else {
        print_line();
        cur_width = word.size();
        line = {std::move(word)};
      }
    }
    if (line.size()) {
      print_line(true);
    }
    return result;
  }
};
// @lc code=end
