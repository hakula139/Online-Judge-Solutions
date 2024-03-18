/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
#include <algorithm>
#include <utility>

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto n1 = length(l1), n2 = length(l2);
    if (n1 < n2) {
      std::swap(l1, l2);
      std::swap(n1, n2);
    }

    ListNode dummy;
    auto node = &dummy;
    for (int i = n2; i < n1; ++i) {
      node->next = new ListNode{l1->val};
      l1 = l1->next;
      node = node->next;
    }
    for (int i = 0; i < n2; ++i) {
      node->next = new ListNode{l1->val + l2->val};
      l1 = l1->next;
      l2 = l2->next;
      node = node->next;
    }

    auto head = dummy.next;
    auto carry = forwardCarry(head);
    return carry ? new ListNode{carry, head} : head;
  }

 private:
  int length(ListNode* root) {
    int result = 0;
    for (; root; root = root->next) {
      ++result;
    }
    return result;
  }

  int forwardCarry(ListNode* root) {
    if (!root) return 0;
    root->val += forwardCarry(root->next);
    auto carry = root->val / 10;
    root->val %= 10;
    return carry;
  }
};
// @lc code=end
