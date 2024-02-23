/*
 * @lc app=leetcode id=393 lang=cpp
 *
 * [393] UTF-8 Validation
 */

// @lc code=start
#include <bit>
#include <vector>

class Solution {
 public:
  bool validUtf8(const std::vector<int>& data) {
    int n_bytes = 0;
    for (int i = 0; i < data.size(); ++i, --n_bytes) {
      if (n_bytes == 0) {
        n_bytes = parseHead(data[i]);
        if (n_bytes <= 0) return false;
      } else if (!checkHead(data[i])) {
        return false;
      }
    }
    return n_bytes == 0;
  }

 private:
  int parseHead(int c) {
    uint8_t head = c & 0xFF;
    auto n_bytes = std::countl_one(head);
    if (n_bytes == 1 || n_bytes > 4) return -1;
    if (n_bytes == 0) return 1;
    return n_bytes;
  }

  bool checkHead(int c) {
    uint8_t head = c & 0xFF;
    return std::countl_one(head) == 1;
  }
};
// @lc code=end
