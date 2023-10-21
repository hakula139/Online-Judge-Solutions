/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) {
    int size = 0;
    for (auto node = head; node; node = node->next, ++size) {
    }
    return sortedListToBST(head, 0, size);
  }

 private:
  TreeNode* sortedListToBST(ListNode*& head, int begin, int end) {
    if (begin >= end) return nullptr;
    int mid = begin + (end - begin) / 2;
    auto root = new TreeNode;
    root->left = sortedListToBST(head, begin, mid);
    root->val = head->val;
    head = head->next;
    root->right = sortedListToBST(head, mid + 1, end);
    return root;
  }
};
// @lc code=end
