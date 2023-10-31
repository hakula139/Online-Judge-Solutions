/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <string>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<std::string>> partition(const std::string& s) {
    initIsPalindromeMatrix(s);
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> parts;
    partition(result, parts, s, 0);
    return result;
  }

 private:
  void initIsPalindromeMatrix(const std::string& s) {
    auto n = s.size();
    is_palindrome_ = {n, std::vector(n, false)};
    for (int i = 0; i < n; ++i) {
      is_palindrome_[i][i] = true;
    }
    for (int i = 0; i < n - 1; ++i) {
      is_palindrome_[i][i + 1] = s[i] == s[i + 1];
    }
    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        is_palindrome_[i][j] = is_palindrome_[i + 1][j - 1] && s[i] == s[j];
      }
    }
  }

  void partition(std::vector<std::vector<std::string>>& result,
                 std::vector<std::string>& parts, const std::string& s, int i) {
    if (i == s.size()) {
      result.push_back(parts);
      return;
    }
    for (int j = i; j < s.size(); ++j) {
      if (isPalindrome(i, j)) {
        parts.emplace_back(s.substr(i, j - i + 1));
        partition(result, parts, s, j + 1);
        parts.pop_back();
      }
    }
  }

  bool isPalindrome(int i, int j) const { return is_palindrome_[i][j]; }

  std::vector<std::vector<bool>> is_palindrome_;
};
// @lc code=end
