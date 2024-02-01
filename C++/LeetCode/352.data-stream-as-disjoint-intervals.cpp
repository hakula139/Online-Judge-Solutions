/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

struct Interval {
  int start;
  int end;

  bool operator<(const Interval& rhs) const { return start < rhs.start; }
};

class SummaryRanges {
 public:
  void addNum(int value) {
    Interval new_interval{value, value};
    bool need_replace = false;

    auto it = data_.lower_bound(value);
    if (it != data_.end()) {
      auto [start, end] = it->second;
      if (value == start) return;
      if (value == start - 1) {
        new_interval.end = end;
        need_replace = true;
      }
    }

    if (it == data_.begin()) {
      data_[value] = std::move(new_interval);
    } else {
      auto prev_it = std::prev(it);
      auto [prev_start, prev_end] = prev_it->second;
      if (prev_end >= value - 1) {
        prev_it->second.end = std::max(prev_end, new_interval.end);
      } else {
        data_[value] = std::move(new_interval);
      }
    }
    if (need_replace) {
      data_.erase(it);
    }
  }

  std::vector<std::vector<int>> getIntervals() {
    std::vector<std::vector<int>> result;
    result.reserve(data_.size());
    for (const auto& [_, interval] : data_) {
      auto [start, end] = interval;
      result.push_back({start, end});
    }
    return result;
  }

 private:
  std::map<int, Interval> data_;
};
// @lc code=end
