/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

class AllOne {
 public:
  using Bucket = std::unordered_set<std::string>;
  using BucketNode = std::pair<size_t, Bucket>;

  void inc(const std::string& key) {
    auto map_it = map_.find(key);
    auto bucket_it = map_it == map_.end() ? buckets_.begin() : map_it->second;
    auto next_bucket_it = std::next(bucket_it);
    auto count = bucket_it->first;
    auto& bucket = bucket_it->second;

    ++count;
    if (next_bucket_it == buckets_.end() || count < next_bucket_it->first) {
      next_bucket_it = buckets_.emplace(next_bucket_it, count, Bucket{{key}});
    } else {
      next_bucket_it->second.insert(key);
    }
    map_[key] = next_bucket_it;

    if (count > 1) {
      bucket.erase(key);
      if (bucket.empty()) {
        buckets_.erase(bucket_it);
      }
    }
  }

  void dec(const std::string& key) {
    auto map_it = map_.find(key);
    if (map_it == map_.end()) return;
    auto bucket_it = map_it->second;
    auto prev_bucket_it = std::prev(bucket_it);
    auto count = bucket_it->first;
    auto& bucket = bucket_it->second;

    if (--count > 0) {
      if (prev_bucket_it == buckets_.begin() || count > prev_bucket_it->first) {
        prev_bucket_it = buckets_.emplace(bucket_it, count, Bucket{{key}});
      } else {
        prev_bucket_it->second.insert(key);
      }
      map_it->second = prev_bucket_it;
    } else {
      map_.erase(map_it);
    }

    bucket.erase(key);
    if (bucket.empty()) {
      buckets_.erase(bucket_it);
    }
  }

  std::string getMaxKey() {
    if (buckets_.size() <= 1) return "";
    return *buckets_.back().second.begin();
  }

  std::string getMinKey() {
    if (buckets_.size() <= 1) return "";
    return *std::next(buckets_.begin())->second.begin();
  }

 private:
  std::list<BucketNode> buckets_{{}};  // dummy node
  std::unordered_map<std::string, std::list<BucketNode>::iterator> map_;
};
// @lc code=end
