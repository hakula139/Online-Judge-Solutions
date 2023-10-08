/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
  ListNode* deleteDuplicates(ListNode* head) {
    for (auto node = head; node && node->next;) {
      if (node->val == node->next->val) {
        node->next = node->next->next;
      } else {
        node = node->next;
      }
    }
    return head;
  }
};
// @lc code=end
