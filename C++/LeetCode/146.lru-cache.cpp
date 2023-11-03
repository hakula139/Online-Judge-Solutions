/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <cassert>
#include <cstdio>
#include <unordered_map>
#include <vector>

struct LRUEntry {
  int key = -1;
  int value = -1;
  LRUEntry* prev = nullptr;
  LRUEntry* next = nullptr;
};

class LRUCache {
 public:
  explicit LRUCache(int capacity) {
    assert(capacity > 0);
    cache_.reserve(capacity);
    pool_ = std::vector<LRUEntry>(capacity);
    for (int i = 0; i < capacity; ++i) {
      pool_[i].prev = i > 0 ? &pool_[i - 1] : &pool_.back();
      pool_[i].next = i < capacity - 1 ? &pool_[i + 1] : &pool_.front();
    }
    tail_ = &pool_[0];
  }

  int get(int key) {
    auto node = update(key);
    auto value = node ? node->value : -1;
    // printf("get(%d) = %d\n", key, value);
    // dump();
    return value;
  }

  void put(int key, int value) {
    if (cache_.contains(key)) {
      update(key, value);
    } else {
      insert(key, value);
    }
    // printf("put(%d, %d)\n", key, value);
    // dump();
  }

 private:
  LRUEntry* insert(int key, int value) {
    tail_ = tail_->next;
    if (tail_->key != key) {
      cache_.erase(tail_->key);
    }
    cache_[key] = tail_;
    tail_->key = key;
    tail_->value = value;
    return tail_;
  }

  LRUEntry* update(int key) {
    auto it = cache_.find(key);
    if (it == cache_.end()) return nullptr;
    auto node = it->second;
    if (node == tail_) return tail_;

    auto prev = node->prev;
    auto next = node->next;
    prev->next = next;
    next->prev = prev;
    node->next = tail_->next;
    node->prev = tail_;
    node->next->prev = node;
    node->prev->next = node;
    tail_ = node;
    return node;
  }

  LRUEntry* update(int key, int value) {
    auto node = update(key);
    node->value = value;
    return node;
  }

  void dump() const {
    printf("- cache = { ");
    for (const auto& [key, entry] : cache_) {
      printf("(%d -> %d) ", key, entry->key);
    }
    printf("}\n");

    printf("- pool = [ ");
    for (const auto& [key, value, prev, next] : pool_) {
      printf("(%d <- %d:%d -> %d) ", prev->key, key, value, next->key);
    }
    printf("]\n");

    printf("- tail = %d\n\n", tail_->value);
  }

  std::unordered_map<int, LRUEntry*> cache_;
  std::vector<LRUEntry> pool_;
  LRUEntry* tail_;
};
// @lc code=end

int main() {
  LRUCache lru{3};
  lru.put(1, 1);
  lru.put(2, 2);
  lru.put(3, 3);
  lru.put(4, 4);
  lru.get(4);
  lru.get(3);
  lru.get(2);
  lru.get(1);
  lru.put(5, 5);
  lru.get(1);
  lru.get(2);
  lru.get(3);
  lru.get(4);
  lru.get(5);
  return 0;
}
