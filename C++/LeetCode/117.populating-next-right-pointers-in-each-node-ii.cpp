/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

struct Node {
  int val;
  Node* left;
  Node* right;
  Node* next;
  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
  explicit Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
  Node(int x, Node* left, Node* right, Node* next)
      : val(x), left(left), right(right), next(next) {}
};

// @lc code=start
class Solution {
 public:
  Node* connect(Node* root) {
    auto head = root;
    while (head) {
      Node *next_head = nullptr, *prev = nullptr;
      auto connect_prev = [&next_head, &prev](Node* node) {
        if (!node) return;
        if (prev) prev->next = node;
        prev = node;
        if (!next_head) next_head = prev;
      };
      for (auto cur = head; cur; cur = cur->next) {
        connect_prev(cur->left);
        connect_prev(cur->right);
      }
      head = next_head;
    }
    return root;
  }
};
// @lc code=end
