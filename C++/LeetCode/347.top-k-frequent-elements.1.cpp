/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <queue>
#include <unordered_map>
#include <vector>

struct NumFreq {
  int num;
  int freq;

  bool operator<(const NumFreq& rhs) const { return freq > rhs.freq; }
};

class Solution {
 public:
  std::vector<int> topKFrequent(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> count;
    for (auto num : nums) {
      ++count[num];
    }

    std::priority_queue<NumFreq> q;
    for (const auto& [num, freq] : count) {
      if (q.size() < k || freq > q.top().freq) {
        q.emplace(num, freq);
      }
      if (q.size() > k) {
        q.pop();
      }
    }

    std::vector<int> result;
    result.reserve(k);
    while (q.size()) {
      result.push_back(q.top().num);
      q.pop();
    }
    return result;
  }
};
// @lc code=end
