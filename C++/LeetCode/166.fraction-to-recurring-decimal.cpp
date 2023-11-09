/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string fractionToDecimal(int numerator, int denominator) {
    if (!numerator) return "0";

    std::string result;
    if (numerator < 0 != denominator < 0) {
      result += '-';
    }
    auto q = std::llabs(numerator);
    auto d = std::llabs(denominator);
    result += std::to_string(q / d);
    auto r = q % d;
    if (!r) return result;
    result += '.';

    std::unordered_map<int64_t, size_t> r_indices;
    bool is_fractional_part = false;
    while (r) {
      auto it = r_indices.find(r);
      if (it != r_indices.end()) {
        result.insert(it->second, "(");
        result += ')';
        break;
      }
      r_indices[r] = result.size();
      q = r * 10;
      r = q % d;
      q /= d;
      result += std::to_string(q);
    }
    return result;
  }
};
// @lc code=end
