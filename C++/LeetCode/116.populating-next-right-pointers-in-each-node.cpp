/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
    if (!root) return root;
    auto head = root;
    while (head->left) {
      for (auto cur = head; cur; cur = cur->next) {
        cur->left->next = cur->right;
        if (cur->next) {
          cur->right->next = cur->next->left;
        }
      }
      head = head->left;
    }
    return root;
  }
};
// @lc code=end
