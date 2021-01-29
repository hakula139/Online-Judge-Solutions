#include <algorithm>
#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
 public:
  int lengthOfLongestSubstring(const string& s) {
    auto str_len = s.size();
    if (!str_len) return 0;

    vector<int> char_pos(UCHAR_MAX, -1);
    auto start_pos = 0;
    auto max_len = 0;

    for (auto end_pos = 0; end_pos < str_len; ++end_pos) {
      auto c = s[end_pos];
      if (char_pos[c] >= start_pos) {
        start_pos = char_pos[c] + 1;
      } else {
        max_len = max(max_len, end_pos - start_pos + 1);
      }
      char_pos[c] = end_pos;
    }
    return max_len;
  }
};
