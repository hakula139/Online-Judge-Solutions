/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
  ListNode* getIntersectionNode(ListNode* head_a, ListNode* head_b) {
    auto cur_a = head_a, cur_b = head_b;
    while (cur_a != cur_b) {
      cur_a = cur_a ? cur_a->next : head_b;
      cur_b = cur_b ? cur_b->next : head_a;
    }
    return cur_a;
  }
};
// @lc code=end
