/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    auto h1 = list1, h2 = list2, h = &dummy;
    while (h1 && h2) {
      if (h1->val < h2->val) {
        h->next = h1;
        h1 = h1->next;
      } else {
        h->next = h2;
        h2 = h2->next;
      }
      h = h->next;
    }
    h->next = h1 ? h1 : h2;
    return dummy.next;
  }
};
// @lc code=end
