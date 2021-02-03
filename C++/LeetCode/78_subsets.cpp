#include <vector>

using std::vector;

class Solution {
 public:
  vector<vector<int>> subsets(const vector<int>& nums) {
    auto len = nums.size();
    auto size = 1 << len;
    vector<vector<int>> result;
    for (auto i = 0; i < size; ++i) {
      vector<int> subset;
      for (auto nums_i = 0; nums_i < len; ++nums_i) {
        if (i & (1 << nums_i)) subset.push_back(nums[nums_i]);
      }
      result.push_back(subset);
    }
    return result;
  }
};
