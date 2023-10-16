/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy{0, head};
    auto prev = &dummy;
    for (int i = 0; i < left - 1; ++i) {
      prev = prev->next;
    }
    auto cur = prev->next;
    for (int i = left; i < right; ++i) {
      auto tmp = prev->next;
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = tmp;
    }
    return dummy.next;
  }
};
// @lc code=end
