/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

struct ListNode {
  int val;
  ListNode* next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
class Solution {
 public:
  ListNode* detectCycle(ListNode* head) {
    auto fast = head, slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        slow = head;
        while (fast != slow) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// @lc code=end
