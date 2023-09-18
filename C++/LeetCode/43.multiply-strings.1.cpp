/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  // Karatsuba algorithm
  std::string multiply(const std::string& num1, const std::string& num2) {
    if (num1.empty() || num1 == "0") return "0";
    if (num2.empty() || num2 == "0") return "0";
    if (num1.size() == 1 && num2.size() == 1) {
      return std::to_string((num1[0] - '0') * (num2[0] - '0'));
    }

    auto n = std::max(num1.size(), num2.size()) >> 1;
    auto x1 = n < num1.size() ? num1.substr(0, num1.size() - n) : "";
    auto x0 = n < num1.size() ? num1.substr(num1.size() - n) : num1;
    auto y1 = n < num2.size() ? num2.substr(0, num2.size() - n) : "";
    auto y0 = n < num2.size() ? num2.substr(num2.size() - n) : num2;

    auto z0 = multiply(x0, y0);
    auto z1 = multiply(add(x0, x1), add(y0, y1));
    auto z2 = multiply(x1, y1);
    z1 = subtract(z1, add(z0, z2));

    return add(add(z0, left_shift(z1, n)), left_shift(z2, n << 1));
  }

  std::string add(const std::string& num1, const std::string& num2) {
    if (num1.empty() || num1 == "0") return num2;
    if (num2.empty() || num2 == "0") return num1;

    std::string result;
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;
         --i, --j) {
      int d1 = i >= 0 ? num1[i] - '0' : 0;
      int d2 = j >= 0 ? num2[j] - '0' : 0;
      int sum = d1 + d2 + carry;
      if (sum >= 10) {
        sum -= 10;
        carry = 1;
      } else {
        carry = 0;
      }
      result += '0' + sum;
    }
    if (carry) {
      result += '1';
    }

    while (result.size() >= 1 && result.back() == '0') {
      result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }

  std::string subtract(const std::string& num1, const std::string& num2) {
    if (num2.empty() || num2 == "0") return num1;

    std::string result;
    int carry = 0;
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0;
         --i, --j) {
      int d1 = i >= 0 ? num1[i] - '0' : 0;
      int d2 = j >= 0 ? num2[j] - '0' : 0;
      int diff = d1 - d2 - carry;
      if (diff < 0) {
        diff += 10;
        carry = 1;
      } else {
        carry = 0;
      }
      result += '0' + diff;
    }
    assert(!carry);  // only support cases where num1 >= num2

    while (result.size() >= 1 && result.back() == '0') {
      result.pop_back();
    }
    std::reverse(result.begin(), result.end());
    return result;
  }

  std::string left_shift(const std::string& num, size_t n) {
    if (num.empty() || num == "0") return num;
    return num + std::string(n, '0');
  }
};
// @lc code=end
