#include <algorithm>
#include <vector>

using std::distance;
using std::lower_bound;
using std::vector;
using It = vector<int>::iterator;

class Solution {
 public:
  int lengthOfLIS(const vector<int>& nums) {
    auto size = nums.size();
    vector<int> dp;
    for (auto num : nums) {
      // auto pos = BinarySearch(dp.begin(), dp.end(), num);
      auto pos = lower_bound(dp.begin(), dp.end(), num);
      if (pos == dp.end()) {
        dp.push_back(num);
      } else {
        *pos = num;
      }
    }
    return dp.size();
  }

 private:
  It BinarySearch(It begin, It end, int target) {
    if (distance(begin, end) < 1) return end;
    auto mid = begin + ((end - begin - 1) >> 1);
    if (*mid == target) {
      return mid;
    } else if (*mid > target) {
      return BinarySearch(begin, mid, target);
    } else {
      return BinarySearch(mid + 1, end, target);
    }
  }
};
