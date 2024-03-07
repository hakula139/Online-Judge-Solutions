/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
#include <array>
#include <string>
#include <vector>

/**
 * Alphabet: efghinorstuvwxz   E   Dep
 *
 * zero      100000110000001   z
 * one       100001100000000   n   7,9
 * two       000000100100100   w
 * three     200100010100000   t   2,8
 * four      010000110010000   u
 * five      110010000001000   f   4
 * six       000010001000010   x
 * seven     200001001001000   v   5
 * eight     101110000100000   g
 * nine      100012000000000   i   5,6,8
 *
 * Order:    0,2,4,6,8,3,5,7,9,1
 */

constexpr size_t kAlphabetSize = 26;
constexpr size_t kDigitCount = 10;

class Solution {
 public:
  std::string originalDigits(const std::string& s) {
    std::array<int, kAlphabetSize> char_count{};
    for (auto c : s) {
      ++char_count[c - 'a'];
    }

    constexpr std::array kOrder{0, 2, 4, 6, 8, 3, 5, 7, 9, 1};
    constexpr auto kEigenChar = "zwuxgtfvin";
    const std::vector<std::string> kWords{
        "zero",  "two",  "four",  "six",  "eight",
        "three", "five", "seven", "nine", "one",
    };
    std::array<int, kDigitCount> digit_count{};
    for (int i = 0; i < kDigitCount; ++i) {
      auto count = char_count[kEigenChar[i] - 'a'];
      digit_count[kOrder[i]] = count;
      for (auto c : kWords[i]) {
        char_count[c - 'a'] -= count;
      }
    }

    std::string result;
    for (int i = 0; i < kDigitCount; ++i) {
      if (digit_count[i] > 0) {
        result += std::string(digit_count[i], '0' + i);
      }
    }
    return result;
  }
};
// @lc code=end
