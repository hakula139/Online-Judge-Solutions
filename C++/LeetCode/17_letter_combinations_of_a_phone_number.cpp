#include <deque>
#include <string>
#include <vector>

using std::deque;
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> letterCombinations(const string& digits) {
    if (digits.empty()) return {};
    vector<string> button_map{
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
    deque<string> result{""};
    for (const auto& digit : digits) {
      auto size = result.size();
      while (size--) {
        auto prefix = result.front();
        result.pop_front();
        auto possible_chars = button_map[digit - '0'];
        for (const auto& c : possible_chars) {
          result.push_back(prefix + c);
        }
      }
    }
    return vector<string>(result.begin(), result.end());
  }
};
