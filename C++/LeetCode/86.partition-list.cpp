/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode* partition(ListNode* head, int x) {
    ListNode low_dummy{0, head}, high_dummy{0, head};
    auto low = &low_dummy, high = &high_dummy;
    for (; head; head = head->next) {
      if (head->val < x) {
        low = low->next = head;
      } else {
        high = high->next = head;
      }
    }
    high->next = nullptr;
    low->next = high_dummy.next;
    return low_dummy.next;
  }
};
// @lc code=end
