/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
#include <cctype>
#include <string>
#include <unordered_set>

class Solution {
 public:
  bool isNumber(const std::string& s) {
    std::unordered_set<char> valid_chars{
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '-', '.',
    };

    bool is_first = true;
    bool has_e = false;
    bool need_digit = true;

    for (int i = 0; i < s.size(); ++i) {
      if (!valid_chars.contains(s[i])) return false;
      if (is_first) {
        is_first = false;
        need_digit = true;
        valid_chars.erase('+');
        valid_chars.erase('-');
      }
      if (std::isdigit(s[i])) {
        need_digit = false;
        if (!has_e) {
          valid_chars.insert('e');
          valid_chars.insert('E');
        }
      }
      switch (s[i]) {
        case '.':
          need_digit = (i == 0) || !std::isdigit(s[i - 1]);
          valid_chars.erase('.');
          break;
        case 'e':
        case 'E':
          is_first = true;
          has_e = true;
          need_digit = true;
          valid_chars.erase('.');
          valid_chars.erase('e');
          valid_chars.erase('E');
          valid_chars.insert('+');
          valid_chars.insert('-');
          break;
        default:
          break;
      }
    }
    return !need_digit;
  }
};
// @lc code=end
