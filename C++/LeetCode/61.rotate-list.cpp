/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
  ListNode* rotateRight(ListNode* head, int k) {
    int len = 0;
    for (auto node = head; node; node = node->next) {
      ++len;
    }
    if (!len) return head;
    k %= len;
    if (!k) return head;

    ListNode *slow = head, *fast = head;
    for (auto i = 0; i < k; ++i) {
      fast = fast->next;
    }
    while (fast->next) {
      fast = fast->next;
      slow = slow->next;
    }
    fast->next = head;
    head = slow->next;
    slow->next = nullptr;
    return head;
  }
};
// @lc code=end
