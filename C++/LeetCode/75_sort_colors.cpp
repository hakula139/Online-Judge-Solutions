#include <vector>

using std::distance;
using std::swap;
using std::vector;
using It = vector<int>::iterator;

class Solution {
 public:
  void sortColors(vector<int>& nums) {  // NOLINT(runtime/references)
    QuickSort(nums.begin(), nums.end());
  }

  void QuickSort(It begin, It end) {
    if (distance(begin, end) <= 1) return;
    auto mid = Partition(begin, end);
    QuickSort(begin, mid);
    QuickSort(mid + 1, end);
  }

  It Partition(It begin, It end) {
    if (distance(begin, end) <= 1) return begin;
    auto tmp = *begin;
    auto left = begin;
    auto right = end - 1;
    while (left < right) {
      while (left < right && *right >= tmp) --right;
      while (left < right && *left <= tmp) ++left;
      swap(*left, *right);
    }
    swap(*begin, *left);
    return left;
  }
};
