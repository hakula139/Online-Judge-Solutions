/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class RandomizedCollection {
 public:
  bool insert(int val) {
    auto ret = !indices_map_.contains(val);
    indices_map_[val].insert(data_.size());
    data_.push_back(val);
    return ret;
  }

  bool remove(int val) {
    auto it = indices_map_.find(val);
    if (it == indices_map_.end()) {
      return false;
    }

    auto& indices = it->second;
    auto i = *indices.begin();
    indices.erase(indices.begin());
    auto back_it = indices_map_.find(data_.back());
    if (back_it != indices_map_.end()) {
      auto& back_indices = back_it->second;
      back_indices.insert(i);
      back_indices.erase(data_.size() - 1);
    }
    data_[i] = data_.back();
    data_.pop_back();
    if (indices.empty()) {
      indices_map_.erase(it);
    }
    return true;
  }

  int getRandom() {
    std::uniform_int_distribution<int> dist(0, data_.size() - 1);
    return data_[dist(rng_)];
  }

 private:
  std::vector<int> data_;
  std::unordered_map<int, std::unordered_set<int>> indices_map_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
