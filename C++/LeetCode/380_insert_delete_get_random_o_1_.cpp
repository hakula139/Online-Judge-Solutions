#include <random>
#include <unordered_map>
#include <vector>

using std::default_random_engine;
using std::swap;
using std::uniform_int_distribution;
using std::unordered_map;
using std::vector;

class RandomizedSet {
 public:
  // Inserts a value to the set. Returns true if the set did not already
  // contain the specified element.
  bool insert(int val) {
    if (set_.count(val)) return false;
    set_[val] = data_.size();
    data_.emplace_back(val);
    return true;
  }

  // Removes a value from the set. Returns true if the set contained the
  // specified element.
  bool remove(int val) {
    if (!set_.count(val)) return false;
    set_[data_.back()] = set_[val];
    swap(data_[set_[val]], data_.back());
    data_.pop_back();
    set_.erase(val);
    return true;
  }

  // Gets a random element from the set.
  int getRandom() {
    uniform_int_distribution<int> distribution(0, data_.size() - 1);
    auto i = distribution(generator_);
    return data_[i];
  }

 private:
  unordered_map<int, int> set_;
  vector<int> data_;
  default_random_engine generator_;
};
