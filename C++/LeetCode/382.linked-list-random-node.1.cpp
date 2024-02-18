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
#include <random>

class Solution {
 public:
  explicit Solution(ListNode* head) : head_{head} {}

  int getRandom() {
    auto result = head_->val, n = 0;
    for (auto node = head_; node; node = node->next) {
      std::uniform_int_distribution dist(0, n++);
      if (dist(rng_) == 0) {
        result = node->val;
      }
    }
    return result;
  }

 private:
  ListNode* head_;
  std::random_device rd_;
  std::mt19937 rng_{rd_()};
};
// @lc code=end
