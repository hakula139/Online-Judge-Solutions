/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <iostream>

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class DisjointSet {
 public:
  int find(int x) {
    auto it = parent_.find(x);
    if (it == parent_.end()) {
      parent_[x] = x;
      size_[x] = 1;
      return x;
    }
    auto& parent = it->second;
    if (parent != x) {
      parent = find(parent);
    }
    return parent;
  }

  void unionBySize(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    auto &size_x = size_[x], &size_y = size_[y];
    if (size_x < size_y) {
      parent_[x] = y;
      size_y += size_x;
      max_size_ = std::max(size_y, max_size_);
      size_.erase(x);
    } else {
      parent_[y] = x;
      size_x += size_y;
      max_size_ = std::max(size_x, max_size_);
      size_.erase(y);
    }
  }

  int max_size() const { return max_size_; }

 private:
  std::unordered_map<int, int> parent_;
  std::unordered_map<int, int> size_;
  int max_size_ = 0;
};

class Solution {
 public:
  int longestConsecutive(const std::vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();
    std::unordered_set<int> nums_set;
    DisjointSet disjoint_set;
    for (auto num : nums) {
      if (nums_set.contains(num)) continue;
      nums_set.insert(num);
      if (nums_set.contains(num - 1)) {
        disjoint_set.unionBySize(num - 1, num);
      }
      if (nums_set.contains(num + 1)) {
        disjoint_set.unionBySize(num + 1, num);
      }
    }
    return std::max(disjoint_set.max_size(), 1);
  }
};
// @lc code=end

int main() {
  Solution sol;
  std::vector<int> nums{
      100, 4, 200, 1, 3, 2,
  };
  auto result = sol.longestConsecutive(nums);
  std::cout << result << '\n';
  return 0;
}
