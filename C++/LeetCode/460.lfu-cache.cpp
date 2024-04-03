/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
#include <cstdio>
#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
 public:
  using List = std::list<int>;

  void put(int key) {
    auto it = cache_.find(key);
    if (it != cache_.end()) {
      list_.erase(it->second);
    }
    cache_[key] = list_.emplace(list_.end(), key);
  }

  void remove(int key) {
    auto it = cache_.find(key);
    if (it == cache_.end()) return;
    list_.erase(it->second);
    cache_.erase(it);
  }

  int pop() {
    auto value = list_.front();
    list_.pop_front();
    cache_.erase(value);
    return value;
  }

  bool empty() const { return !cache_.size(); }

 private:
  std::unordered_map<int, List::iterator> cache_;
  List list_;
};

class LFUCache {
 public:
  using LRUList = std::list<std::pair<int, LRUCache>>;

  explicit LFUCache(int capacity) : capacity_{capacity} {}

  int get(int key) {
    auto it = cache_.find(key);
    if (it == cache_.end()) {
      // printf("get(%d) not exist\n", key);
      return -1;
    }
    auto& [value, freq] = it->second;
    update(key, freq++);
    // printf("get(%d) = %d\n", key, value);
    return value;
  }

  void put(int key, int value) {
    if (!cache_.contains(key) && cache_.size() == capacity_) {
      invalidate();
    }
    auto& [cur_value, freq] = cache_[key];
    cur_value = value;
    update(key, freq++);
    // printf("put(%d, %d)\n", key, value);
  }

 private:
  void update(int key, int freq) {
    auto lru_it = lru_list_.begin();
    if (freq > 0) {
      auto buckets_it = buckets_.find(freq);
      lru_it = buckets_it->second;
      auto& lru = lru_it->second;
      lru.remove(key);
      if (lru.empty()) {
        lru_it = lru_list_.erase(lru_it);
        buckets_.erase(buckets_it);
      } else {
        ++lru_it;
      }
    }

    ++freq;
    if (lru_it == lru_list_.end() || lru_it->first > freq) {
      lru_it = lru_list_.emplace(lru_it, freq, LRUCache{});
      buckets_[freq] = lru_it;
    }
    auto& lru = lru_it->second;
    lru.put(key);
  }

  void invalidate() {
    auto lru_it = lru_list_.begin();
    auto& [freq, lru] = *lru_it;
    auto key = lru.pop();
    cache_.erase(key);
    if (lru.empty()) {
      buckets_.erase(freq);
      lru_list_.erase(lru_it);
    }
  }

  int capacity_;
  std::unordered_map<int, std::pair<int, int>> cache_;
  std::unordered_map<int, LRUList::iterator> buckets_;
  LRUList lru_list_;
};
// @lc code=end

int main() {
  LFUCache lfu{2};
  lfu.put(1, 1);
  lfu.put(2, 2);
  lfu.get(1);
  lfu.put(3, 3);
  lfu.get(2);
  lfu.get(3);
  lfu.put(4, 4);
  lfu.get(1);
  lfu.get(3);
  lfu.get(4);
  return 0;
}
