/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
#include <cstdio>
#include <functional>
#include <map>
#include <numeric>
#include <vector>

class WeightedTree {
 public:
  using It = std::map<int, int>::iterator;

  It insert(int x) {
    if (mid_it_ == data_.end()) {
      mid_it_ = data_.emplace(x, 1).first;
      return mid_it_;
    }

    auto& cur_weight = mid_it_->second;
    if (x == mid_it_->first) {
      ++cur_weight;
      return mid_it_;
    }

    ++data_[x];
    if (x < mid_it_->first) {
      ++left_weight_;
      moveLeft();
    } else {
      ++right_weight_;
      moveRight();
    }
    return mid_it_;
  }

  It erase(int x) {
    auto& cur_weight = mid_it_->second;
    if (x == mid_it_->first) {
      if (--cur_weight == 0) {
        eraseMid();
      }
      return mid_it_;
    }

    auto it = data_.find(x);
    if (it != data_.end() && --it->second == 0) {
      data_.erase(it);
    }
    if (x < mid_it_->first) {
      --left_weight_;
      moveRight();
    } else {
      --right_weight_;
      moveLeft();
    }
    return mid_it_;
  }

  double oddMedian() const { return mid_it_->first; }

  double evenMedian() const {
    if (left_weight_ + mid_it_->second > right_weight_) {
      return mid_it_->first;
    }
    return std::midpoint<double>(mid_it_->first, std::next(mid_it_)->first);
  }

  void dump() {
    printf("%d <- (%d) -> %d, ", left_weight_, mid_it_->first, right_weight_);
    for (const auto& [x, count] : data_) {
      printf("{%d: %d} ", x, count);
    }
    printf("\n");
  }

 private:
  void moveLeft() {
    auto& cur_weight = mid_it_->second;
    if (left_weight_ >= cur_weight + right_weight_) {
      right_weight_ += cur_weight;
      --mid_it_;
      left_weight_ -= mid_it_->second;
    }
  }

  void moveRight() {
    auto& cur_weight = mid_it_->second;
    if (left_weight_ + cur_weight < right_weight_) {
      left_weight_ += cur_weight;
      ++mid_it_;
      right_weight_ -= mid_it_->second;
    }
  }

  void eraseMid() {
    if (left_weight_ >= right_weight_) {
      data_.erase(std::next(--mid_it_));
      left_weight_ -= mid_it_->second;
    } else {
      data_.erase(std::prev(++mid_it_));
      right_weight_ -= mid_it_->second;
    }
  }

  std::map<int, int> data_;
  It mid_it_ = data_.end();
  size_t left_weight_ = 0;
  size_t right_weight_ = 0;
};

class Solution {
 public:
  std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k) {
    if (k == 1) return {nums.begin(), nums.end()};

    WeightedTree tree;
    std::vector<double> result;
    auto get_median = std::mem_fn(
        k % 2 ? &WeightedTree::oddMedian : &WeightedTree::evenMedian);

    for (int i = 0; i < k - 1; ++i) {
      tree.insert(nums[i]);
    }
    for (int i = k - 1; i < nums.size(); ++i) {
      tree.insert(nums[i]);
      // tree.dump();
      result.push_back(get_median(tree));
      tree.erase(nums[i - k + 1]);
      // tree.dump();
    }
    return result;
  }
};
// @lc code=end
