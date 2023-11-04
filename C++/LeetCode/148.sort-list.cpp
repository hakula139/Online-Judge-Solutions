/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
  ListNode* sortList(ListNode* head) {
    int size = 0;
    for (auto node = head; node; node = node->next, ++size) {
    }
    if (size < 2) return head;

    ListNode dummy{0, head};
    for (int step = 1; step < size; step <<= 1) {
      auto cur = dummy.next, tail = &dummy;
      while (cur) {
        auto left = cur;
        auto right = splitAt(left, step);
        cur = splitAt(right, step);
        tail = merge(left, right, tail);
      }
    }
    return dummy.next;
  }

 private:
  ListNode* splitAt(ListNode* head, int k) {
    if (!head || k <= 0) return head;
    while (head->next && --k) {
      head = head->next;
    }
    auto next = head->next;
    head->next = nullptr;
    return next;
  }

  ListNode* merge(ListNode* h1, ListNode* h2, ListNode* out) {
    while (h1 && h2) {
      if (h1->val < h2->val) {
        out->next = h1;
        h1 = h1->next;
      } else {
        out->next = h2;
        h2 = h2->next;
      }
      out = out->next;
    }
    out->next = h1 ? h1 : h2;
    while (out->next) {
      out = out->next;
    }
    return out;
  }
};
// @lc code=end
