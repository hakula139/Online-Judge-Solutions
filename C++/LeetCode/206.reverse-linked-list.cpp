/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
  ListNode* reverseList(ListNode* head) {
    ListNode dummy;
    auto cur = head, prev = &dummy;
    while (cur) {
      auto next = cur->next;
      cur->next = prev->next;
      prev->next = cur;
      cur = next;
    }
    return dummy.next;
  }
};
// @lc code=end
