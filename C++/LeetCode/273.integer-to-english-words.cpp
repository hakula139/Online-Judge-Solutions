/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::string numberToWords(int num) { return num ? transform(num) : "Zero"; }

 private:
  std::string transform(int num) {
    static const std::vector kNumsBelow20{
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    };
    static const std::vector kTens{
        "",      "Ten",   "Twenty",  "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety",
    };
    static const std::vector<std::pair<int, std::string>> kSuffixesAbove100{
        {1000000000, " Billion"},
        {1000000, " Million"},
        {1000, " Thousand"},
        {100, " Hundred"},
    };

    if (num < 20) return kNumsBelow20[num];
    if (num < 100) return join(kTens[num / 10], transform(num % 10));
    for (const auto& [limit, suffix] : kSuffixesAbove100) {
      if (num >= limit) {
        return join(transform(num / limit) + suffix, transform(num % limit));
      }
    }
    return "";
  }

  std::string join(const std::string& s1, const std::string& s2) {
    return s2.empty() ? s1 : s1 + ' ' + s2;
  }
};
// @lc code=end
