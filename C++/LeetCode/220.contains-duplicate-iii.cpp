/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <vector>

class SlidingWindow {
 public:
  explicit SlidingWindow(int capacity, int diff)
      : capacity_{capacity}, diff_{diff} {}

  void push(int num) {
    window_.push(num);
    buckets_[bucket(num)] = num;
    if (window_.size() > capacity_) {
      pop();
    }
  }

  void pop() {
    buckets_.erase(bucket(window_.front()));
    window_.pop();
  }

  bool fuzzyContains(int num) const {
    auto bucket_i = bucket(num);
    if (buckets_.contains(bucket_i)) {
      return true;
    }
    if (diff_ == 0) return false;
    auto prev_it = buckets_.find(bucket_i - 1);
    if (prev_it != buckets_.end() && prev_it->second >= num - diff_) {
      return true;
    }
    auto next_it = buckets_.find(bucket_i + 1);
    if (next_it != buckets_.end() && next_it->second <= num + diff_) {
      return true;
    }
    return false;
  }

 private:
  int bucket(int num) const {
    if (num >= 0) return num / (diff_ + 1);
    return (num + 1) / (diff_ + 1) - 1;
  }

  int capacity_;
  int diff_;
  std::queue<int> window_;
  std::unordered_map<int, int> buckets_;
};

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(
      const std::vector<int>& nums, int index_diff, int value_diff) {
    SlidingWindow window{index_diff, value_diff};
    for (auto num : nums) {
      if (window.fuzzyContains(num)) {
        return true;
      }
      window.push(num);
    }
    return false;
  }
};
// @lc code=end
