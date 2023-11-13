/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy{0, head};
    for (auto node = &dummy; node->next;) {
      if (node->next->val == val) {
        auto next = node->next->next;
        delete node->next;
        node->next = next;
      } else {
        node = node->next;
      }
    }
    return dummy.next;
  }
};
// @lc code=end
