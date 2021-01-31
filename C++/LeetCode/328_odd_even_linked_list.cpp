struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) return head;

    auto last_odd = head;
    auto first_even = head->next;
    auto next_odd = last_odd;
    auto next_even = first_even;

    while (next_even && next_even->next) {
      next_odd = next_even->next;

      next_even->next = next_odd->next;
      next_even = next_even->next;

      last_odd->next = next_odd;
      next_odd->next = first_even;
      last_odd = last_odd->next;
    }
    return head;
  }
};
