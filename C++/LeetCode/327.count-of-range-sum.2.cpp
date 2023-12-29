/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
#include <set>
#include <unordered_map>
#include <vector>

class BIT {
 public:
  explicit BIT(size_t size) : count_(size + 1) {}

  void add(int index, int delta = 1) {
    for (int i = index + 1; i < count_.size(); i += lsb(i)) {
      count_[i] += delta;
    }
  }

  int count(int left, int right) const {
    return count(right + 1) - count(left);
  }

 private:
  // Least Significant Bit
  int lsb(int x) const { return x & -x; }

  int count(int i) const {
    int result = 0;
    for (; i > 0; i -= lsb(i)) {
      result += count_[i];
    }
    return result;
  }

  std::vector<int> count_;
};

class Solution {
 public:
  int countRangeSum(const std::vector<int>& nums, int lower, int upper) {
    std::vector<int64_t> sum(nums.size() + 1);
    for (int i = 1; i <= nums.size(); ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }

    std::set<int64_t> set;
    for (auto x : sum) {
      set.insert(x);
      set.insert(x - upper);
      set.insert(x - lower);
    }

    std::unordered_map<int64_t, int> hash_idx;
    hash_idx.reserve(set.size());
    for (int i = 0; auto x : set) {
      hash_idx[x] = i++;
    }

    BIT bit(hash_idx.size());
    int count = 0;
    for (auto x : sum) {
      auto i = hash_idx[x];
      auto j = hash_idx[x - upper];
      auto k = hash_idx[x - lower];
      count += bit.count(j, k);
      bit.add(i);
    }
    return count;
  }
};
// @lc code=end
