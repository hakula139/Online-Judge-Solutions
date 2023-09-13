/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto dummy = new ListNode{-1, head};
    ListNode *slow = dummy, *fast = dummy;
    for (int i = 0; i <= n; ++i) {
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }

    auto del_node = slow->next;
    slow->next = del_node->next;
    delete del_node;

    head = dummy->next;
    delete dummy;
    return head;
  }
};
// @lc code=end
