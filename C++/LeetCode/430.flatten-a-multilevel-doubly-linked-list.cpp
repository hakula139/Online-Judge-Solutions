/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

struct Node {
  int val;
  Node* prev;
  Node* next;
  Node* child;
};

// @lc code=start
class Solution {
 public:
  Node* flatten(Node* head) {
    flattenHelper(head);
    return head;
  }

 private:
  Node* flattenHelper(Node* head) {
    auto tail = head;
    for (auto node = head; node;) {
      auto next = node->next;
      auto& child = node->child;
      if (child) {
        tail = flattenHelper(child);
        node->next = child;
        child->prev = node;
        tail->next = next;
        if (next) next->prev = tail;
        child = nullptr;
      } else {
        tail = node;
      }
      node = next;
    }
    return tail;
  }
};
// @lc code=end
