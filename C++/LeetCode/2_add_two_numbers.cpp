#include <tuple>

using std::tuple;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
    ListNode* h3 = new ListNode{-1};  // dummy node
    auto [i1, i2, i3] = tuple{h1, h2, h3};
    auto remainder = 0;

    for (; i1 || i2; i3 = i3->next) {
      auto [i1_val, i2_val] = tuple{0, 0};
      if (i1) {
        i1_val = i1->val;
        i1 = i1->next;
      }
      if (i2) {
        i2_val = i2->val;
        i2 = i2->next;
      }
      auto sum = i1_val + i2_val + remainder;
      i3->next = new ListNode{sum % 10};
      remainder = sum / 10;
    }
    if (remainder) i3->next = new ListNode{remainder};

    i3 = h3->next;
    delete h3;  // delete dummy node
    return i3;
  }
};
