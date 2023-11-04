/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
#include <queue>
#include <vector>

struct CompareListNode {
  bool operator()(ListNode* lhs, ListNode* rhs) {
    return !lhs || rhs && lhs->val > rhs->val;
  }
};

class Solution {
 public:
  ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, CompareListNode>
        heads(lists.begin(), lists.end());
    ListNode dummy;
    auto merged_h = &dummy;
    while (heads.size()) {
      auto min_h = heads.top();
      heads.pop();
      if (!min_h) continue;
      merged_h->next = min_h;
      merged_h = merged_h->next;
      if (min_h->next) {
        heads.push(min_h->next);
      }
    }
    return dummy.next;
  }
};
// @lc code=end
