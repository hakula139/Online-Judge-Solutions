/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode dummy{0, head};
    auto slow = &dummy, fast = head;
    for (; fast && fast->next; fast = fast->next) {
      if (fast->val != fast->next->val) {
        slow = slow->next;
      } else {
        while (fast->next && fast->val == fast->next->val) {
          fast = fast->next;
        }
        slow->next = fast->next;
      }
    }
    return dummy.next;
  }
};
// @lc code=end
