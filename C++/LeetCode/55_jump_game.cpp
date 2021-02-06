#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  bool canJump(const vector<int>& nums) {
    int size = nums.size();
    int min_i = size - 1;
    for (auto i = min_i - 1; i >= 0; --i) {
      if (i + nums[i] >= min_i) min_i = i;
    }
    return min_i == 0;
  }
};
