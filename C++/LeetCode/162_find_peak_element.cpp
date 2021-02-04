#include <vector>

using std::distance;
using std::vector;
using It = vector<int>::const_iterator;

class Solution {
 public:
  int findPeakElement(const vector<int>& nums) {
    auto peak = FindPeakElement(nums.begin(), nums.end());
    return distance(nums.begin(), peak);
  }

 private:
  It FindPeakElement(It begin, It end) {
    if (distance(begin, end) <= 1) return begin;
    auto mid = begin + ((end - begin - 1) >> 1);
    if (*mid > *(mid + 1)) {
      return FindPeakElement(begin, mid + 1);
    } else {
      return FindPeakElement(mid + 1, end);
    }
  }
};
