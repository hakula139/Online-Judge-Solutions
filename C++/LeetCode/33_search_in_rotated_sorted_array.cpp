#include <vector>

using std::distance;
using std::vector;
using It = vector<int>::const_iterator;

class Solution {
 public:
  int search(const vector<int>& nums, int target) {
    auto pos = BinarySearch(nums.begin(), nums.end(), target);
    if (pos == nums.end()) return -1;
    return distance(nums.begin(), pos);
  }

 private:
  It BinarySearch(It begin, It end, int target) {
    if (distance(begin, end) < 1) return end;
    auto mid = begin + ((end - begin - 1) >> 1);
    if (*mid == target) return mid;

    auto left_side = true;
    if (*begin <= *mid) {
      left_side = (target >= *begin && target < *mid);
    } else {  // *mid <= *end
      left_side = !(target > *mid && target <= *(end - 1));
    }

    if (left_side) {
      auto pos = BinarySearch(begin, mid, target);
      return pos == mid ? end : pos;
    } else {
      return BinarySearch(mid + 1, end, target);
    }
  }
};
