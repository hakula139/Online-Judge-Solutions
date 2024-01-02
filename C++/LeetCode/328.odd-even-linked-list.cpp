/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;
    auto odd_tail = head, even_head = head->next, even_tail = even_head;
    while (even_tail && even_tail->next) {
      odd_tail->next = odd_tail->next->next;
      even_tail->next = even_tail->next->next;
      odd_tail = odd_tail->next;
      even_tail = even_tail->next;
    }
    odd_tail->next = even_head;
    return head;
  }
};
// @lc code=end
