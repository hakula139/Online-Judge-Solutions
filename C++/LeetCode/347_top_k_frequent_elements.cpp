#include <unordered_map>
#include <vector>

using std::distance;
using std::pair;
using std::swap;
using std::unordered_map;
using std::vector;
using It = vector<pair<int, int>>::iterator;

class Solution {
 public:
  vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (const auto& num : nums) ++freq[num];

    vector<pair<int, int>> freq_arr(freq.begin(), freq.end());
    auto left = freq_arr.begin();
    auto right = freq_arr.end();
    auto pos = freq_arr.begin();
    auto pivot = 1;
    while (true) {
      auto dist = distance(pos, freq_arr.end());
      if (dist == k) break;
      if (dist < k) {
        right = pos;
        pos = Partition(left, right, --pivot);
      } else {
        left = pos;
        pos = Partition(left, right, ++pivot);
      }
    }

    vector<int> result;
    for (auto i = pos; i < freq_arr.end(); ++i) {
      result.push_back(i->first);
    }
    return result;
  }

 private:
  It Partition(It begin, It end, int pivot) {
    if (distance(begin, end) <= 1) return begin;
    auto left = begin;
    auto right = end - 1;
    while (left < right) {
      while (left < right && right->second >= pivot) --right;
      while (left < right && left->second < pivot) ++left;
      swap(*left, *right);
    }
    return left;
  }
};
