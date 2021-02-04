#include <vector>

using std::distance;
using std::vector;
using It = vector<int>::const_iterator;

class Solution {
 public:
  vector<int> searchRange(const vector<int>& nums, int target) {
    auto pos = BinarySearch(nums.begin(), nums.end(), target);
    if (pos == nums.end()) return {-1, -1};
    auto left = pos;
    auto right = pos;
    while (left >= nums.begin() && *left == target) --left;
    while (right < nums.end() && *right == target) ++right;
    return {
        static_cast<int>(distance(nums.begin(), ++left)),
        static_cast<int>(distance(nums.begin(), --right)),
    };
  }

 private:
  It BinarySearch(It begin, It end, int target) {
    if (distance(begin, end) < 1) return end;
    auto mid = begin + ((end - begin - 1) >> 1);
    if (*mid == target) {
      return mid;
    } else if (*mid > target) {
      auto pos = BinarySearch(begin, mid, target);
      return pos == mid ? end : pos;
    } else {
      return BinarySearch(mid + 1, end, target);
    }
  }
};
