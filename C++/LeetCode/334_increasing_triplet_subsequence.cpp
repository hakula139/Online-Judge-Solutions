#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

class Solution {
 public:
  bool increasingTriplet(const vector<int>& nums) {
    if (nums.size() < 3) return false;

    auto [num_1, num_2] = tuple{INT_MAX, INT_MAX};
    for (const auto& num : nums) {
      if (num <= num_1)
        num_1 = num;
      else if (num <= num_2)
        num_2 = num;
      else
        return true;
    }
    return false;
  }
};
