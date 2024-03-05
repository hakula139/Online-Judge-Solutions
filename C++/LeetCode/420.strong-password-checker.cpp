/*
 * @lc app=leetcode id=420 lang=cpp
 *
 * [420] Strong Password Checker
 */

// @lc code=start
#include <algorithm>
#include <string>

class Solution {
 public:
  int strongPasswordChecker(const std::string& password) {
    int n = password.size();

    if (n < 5) return 6 - n;

    int n_add_type = 3;
    n_add_type -= std::any_of(password.begin(), password.end(), ::islower);
    n_add_type -= std::any_of(password.begin(), password.end(), ::isupper);
    n_add_type -= std::any_of(password.begin(), password.end(), ::isdigit);

    if (n == 5) return std::max(1, n_add_type);

    int n_replace = 0, n_del_1 = 0, n_del_2 = 0;
    for (int i = 1, n_repeat = 1; i < n; ++i) {
      for (; i < n && password[i] == password[i - 1]; ++i) {
        n_repeat++;
      }
      if (n_repeat >= 3) {
        n_replace += n_repeat / 3;
        if (n_repeat % 3 == 0) {
          n_del_1++;
        } else if (n_repeat % 3 == 1) {
          n_del_2 += 2;
        }
      }
      n_repeat = 1;
    }

    if (n <= 20) return std::max(n_replace, n_add_type);

    int n_need_del = n - 20;
    n_replace -= std::min(n_need_del, n_del_1);
    n_replace -= std::min(std::max(n_need_del - n_del_1, 0), n_del_2) / 2;
    n_replace -= std::max(n_need_del - n_del_1 - n_del_2, 0) / 3;
    return n_need_del + std::max(n_replace, n_add_type);
  }
};
// @lc code=end
