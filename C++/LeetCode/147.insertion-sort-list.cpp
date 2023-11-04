/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
  ListNode* insertionSortList(ListNode* head) {
    ListNode dummy;
    while (head) {
      ListNode *cur = dummy.next, *prev = &dummy;
      while (cur && cur->val < head->val) {
        prev = cur;
        cur = cur->next;
      }
      auto next = head->next;
      head->next = prev->next;
      prev->next = head;
      head = next;
    }
    return dummy.next;
  }
};
// @lc code=end
