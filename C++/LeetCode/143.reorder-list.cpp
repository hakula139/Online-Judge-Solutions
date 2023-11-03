/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
  void reorderList(ListNode* head) {
    if (!head) return;

    // Find the middle node.
    auto prev_mid = head, tail = head;
    while (tail->next && tail->next->next) {
      tail = tail->next->next;
      prev_mid = prev_mid->next;
    }

    // Reverse the second half.
    ListNode *cur = prev_mid->next, *mid = nullptr;
    while (cur) {
      auto next = cur->next;
      cur->next = mid;
      mid = cur;
      cur = next;
    }

    // Split into two lists.
    prev_mid->next = nullptr;

    // Zip two lists into one list.
    while (mid) {
      auto mid_next = mid->next;
      mid->next = head->next;
      head->next = mid;
      head = mid->next;
      mid = mid_next;
    }
  }
};
// @lc code=end
