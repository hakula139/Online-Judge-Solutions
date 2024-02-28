/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 */

// @lc code=start
#include <algorithm>
#include <utility>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> reconstructQueue(
      std::vector<std::vector<int>>& people) {
    std::sort(
        people.begin(), people.end(), [](const auto& lhs, const auto& rhs) {
          return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
        });

    init(people.size());
    std::vector<std::vector<int>> result(people.size());
    for (auto&& person : people) {
      auto i = binarySearch(person[1]);
      result[i] = std::move(person);
      // Besides updating the nodes on the right, we also update current node to
      // prevent future collision.
      update(i, -1);
    }
    return result;
  }

 private:
  // Least Significant Bit
  int lsb(int i) const { return i & -i; }

  void init(int n) {
    count_ = std::vector<int>(n + 1);
    // count_[1] = 0, as there's no empty slot on the left of the first slot.
    for (int i = 2; i <= n; ++i) {
      ++count_[i];
      int next = i + lsb(i);
      if (next <= n) {
        count_[next] += count_[i];
      }
    }
  }

  void update(int i, int val) {
    for (++i; i < count_.size(); i += lsb(i)) {
      count_[i] += val;
    }
  }

  int get(int i) const {
    int result = 0;
    for (++i; i > 0; i -= lsb(i)) {
      result += count_[i];
    }
    return result;
  }

  // Find the first slot matched with target.
  int binarySearch(int target) const {
    int begin = 0, end = count_.size() - 1;
    while (begin < end) {
      int mid = begin + (end - begin) / 2;
      if (get(mid) < target) {
        begin = mid + 1;
      } else {
        end = mid;
      }
    }
    return begin;
  }

  // Count of empty slots on the left (exclusive).
  std::vector<int> count_;  // Binary Indexed Tree (Fenwick Tree)
};
// @lc code=end
