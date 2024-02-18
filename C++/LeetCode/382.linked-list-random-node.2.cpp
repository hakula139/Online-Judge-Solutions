/*
 * @lc app=leetcode id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

constexpr int kIntMax = 10000;
constexpr int kIntMin = -10000;

class Solution {
 public:
  explicit Solution(ListNode* head) : acc_freq_(kIntMax - kIntMin + 2) {
    std::vector<int> freq(acc_freq_.size());
    for (auto node = head; node; node = node->next) {
      ++freq[node->val - kIntMin];
    }
    std::exclusive_scan(freq.begin(), freq.end(), acc_freq_.begin(), 0);
  }

  int getRandom() {
    auto size = acc_freq_.back();
    std::uniform_int_distribution dist(0, size - 1);
    auto i = dist(rng_);
    auto it = std::upper_bound(acc_freq_.begin(), acc_freq_.end(), i);
    return it - acc_freq_.begin() + kIntMin - 1;
  }

 private:
  std::vector<int> acc_freq_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
