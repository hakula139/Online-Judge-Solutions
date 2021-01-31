#include <tuple>

using std::tuple;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *h1, ListNode *h2) {
    auto [i1, i2] = tuple{h1, h2};
    while (i1 || i2) {
      if (i1 == i2) return i1;
      i1 = !i1 ? h2 : i1->next;
      i2 = !i2 ? h1 : i2->next;
    }
    return nullptr;
  }
};
