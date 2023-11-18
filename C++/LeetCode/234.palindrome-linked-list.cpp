/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode* head) {
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    if (fast == slow) return true;
    if (fast) {
      slow = slow->next;
    }
    slow = reverseList(slow);
    for (; slow; slow = slow->next, head = head->next) {
      if (slow->val != head->val) {
        return false;
      }
    }
    return true;
  }

 private:
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
