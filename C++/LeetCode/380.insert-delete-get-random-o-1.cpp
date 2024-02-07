/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
 public:
  bool insert(int val) {
    if (!indices_.emplace(val, data_.size()).second) {
      return false;
    }
    data_.push_back(val);
    return true;
  }

  bool remove(int val) {
    auto it = indices_.find(val);
    if (it == indices_.end()) {
      return false;
    }
    indices_[data_.back()] = it->second;
    data_[it->second] = data_.back();
    data_.pop_back();
    indices_.erase(it);
    return true;
  }

  int getRandom() {
    std::uniform_int_distribution<int> dist(0, data_.size() - 1);
    return data_[dist(rng_)];
  }

 private:
  std::vector<int> data_;
  std::unordered_map<int, int> indices_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
