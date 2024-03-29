/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    auto i = l1, j = l2, k = &dummy;
    while (i || j) {
      int sum = 0;
      if (i) {
        sum += i->val;
        i = i->next;
      }
      if (j) {
        sum += j->val;
        j = j->next;
      }
      if (k->next) {
        sum += k->next->val;
        k->next->val = sum % 10;
      } else {
        k->next = new ListNode{sum % 10};
      }
      k = k->next;
      if (sum >= 10) {
        k->next = new ListNode{1};
      }
    }
    return dummy.next;
  }
};
// @lc code=end
