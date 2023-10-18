/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
#include <string>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(const std::string& s) {
    std::vector<std::string> result;
    std::vector<int> seps;
    restoreIpAddresses(result, seps, s, 0, 4);
    return result;
  }

 private:
  void restoreIpAddresses(
      std::vector<std::string>& result, std::vector<int>& seps,
      const std::string& s, int i, int n_parts) {
    if (i == s.size()) {
      if (n_parts == 0) {
        auto ip = s.substr(0, seps[0]);
        for (int j = 1; j < seps.size(); ++j) {
          ip += '.' + s.substr(seps[j - 1], seps[j] - seps[j - 1]);
        }
        result.emplace_back(std::move(ip));
      }
      return;
    }
    if (i + 3 * n_parts < s.size() || n_parts > s.size()) {
      return;
    }

    seps.push_back(i + 1);
    restoreIpAddresses(result, seps, s, i + 1, n_parts - 1);
    if (i + 1 < s.size() && s[i] != '0') {
      ++seps.back();
      restoreIpAddresses(result, seps, s, i + 2, n_parts - 1);
      if (i + 2 < s.size() && std::stoi(s.substr(i, 3)) <= 255) {
        ++seps.back();
        restoreIpAddresses(result, seps, s, i + 3, n_parts - 1);
      }
    }
    seps.pop_back();
  }
};
// @lc code=end
