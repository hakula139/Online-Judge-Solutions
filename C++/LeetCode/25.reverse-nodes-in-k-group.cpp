/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* next_group = nullptr;
    auto new_head = reverseKNodes(head, &next_group, k);
    if (!new_head) return head;
    head->next = reverseKGroup(next_group, k);
    return new_head;
  }

 private:
  ListNode* reverseKNodes(ListNode* head, ListNode** next_group, int k) {
    if (!head) {
      *next_group = nullptr;
      return nullptr;
    }
    if (k == 1) {
      *next_group = head->next;
      return head;
    }
    auto new_head = reverseKNodes(head->next, next_group, k - 1);
    if (!new_head) {
      return nullptr;  // less than k nodes, not reversing
    }
    head->next->next = head;
    return new_head;
  }
};
// @lc code=end
