/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

struct Node {
  int val;
  Node* next;
  Node* random;
  Node() : val(0), next(nullptr), random(nullptr) {}
  explicit Node(int val) : val(val), next(nullptr), random(nullptr) {}
};

// @lc code=start
#include <unordered_map>

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    std::unordered_map<Node*, Node*> new_map;
    Node dummy{0};
    for (auto node = head, new_node = &dummy; node; node = node->next) {
      new_node->next = new Node{node->val};
      new_node = new_node->next;
      new_node->random = node->random;
      new_map[node] = new_node;
    }
    for (auto node = dummy.next; node; node = node->next) {
      node->random = new_map[node->random];
    }
    return dummy.next;
  }
};
// @lc code=end
