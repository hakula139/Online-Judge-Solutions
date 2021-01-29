#include <string>

using std::string;

class Solution {
 public:
  string longestPalindrome(const string& s) {
    auto str_len = s.size();
    if (str_len <= 1) return s;

    auto max_len = 1;
    auto result_start = 0;

    for (auto start = 0; start < str_len; ++start) {
      auto left = start;
      auto right = start;
      while (right <= str_len - 2 && s[right] == s[right + 1]) ++right;
      while (left >= 1 && right <= str_len - 2 && s[left - 1] == s[right + 1]) {
        --left, ++right;
      }
      auto len = right - left + 1;
      if (len > max_len) {
        max_len = len;
        result_start = left;
      }
    }

    return s.substr(result_start, max_len);
  }
};
